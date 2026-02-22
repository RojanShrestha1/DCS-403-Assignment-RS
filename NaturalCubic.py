import numpy as np
import matplotlib.pyplot as plt


# 1) Thomas Algorithm (Tridiagonal Solver)

def thomas_solve(a, b, c, d):
    """
    Solve a tridiagonal system:
      a[i]*x[i-1] + b[i]*x[i] + c[i]*x[i+1] = d[i]
    where:
      a[0] is unused (or 0),
      c[-1] is unused (or 0).
    """
    n = len(b)

    
    ac, bc, cc, dc = a.astype(float).copy(), b.astype(float).copy(), c.astype(float).copy(), d.astype(float).copy()


    for i in range(1, n):
        w = ac[i] / bc[i - 1]
        bc[i] = bc[i] - w * cc[i - 1]
        dc[i] = dc[i] - w * dc[i - 1]

    
    x = np.zeros(n, dtype=float)
    x[-1] = dc[-1] / bc[-1]
    for i in range(n - 2, -1, -1):
        x[i] = (dc[i] - cc[i] * x[i + 1]) / bc[i]

    return x



# 2) Natural Cubic Spline Coefficients

def natural_cubic_spline_coeffs(x, y):
    """
    Returns coefficients for each interval:
      S_i(t) = a[i] + b[i]*t + c[i]*t^2 + d[i]*t^3
    where t = (x_val - x[i]) and interval is [x[i], x[i+1]].
    """
    x = np.asarray(x, dtype=float)
    y = np.asarray(y, dtype=float)

    n = len(x) - 1
    if n < 1:
        raise ValueError("Need at least two data points.")

    h = np.diff(x)
    if np.any(h <= 0):
        raise ValueError("x must be strictly increasing.")

 
    if n == 1:
       
        a = y[:-1].copy()
        b = np.array([(y[1] - y[0]) / h[0]])
        c = np.array([0.0])
        d = np.array([0.0])
        return a, b, c, d

    m = n - 1  

 
    L = np.zeros(m)
    D = np.zeros(m)
    U = np.zeros(m)
    R = np.zeros(m)

    for i in range(1, n):  # i = 1..n-1
        row = i - 1  # 0..m-1
        h_im1 = h[i - 1]
        h_i = h[i] if i < n else 0.0

        # Diagonals
        D[row] = 2 * (h_im1 + h[i] if i < n else h_im1)  # but i is never n here
        if row - 1 >= 0:
            L[row] = h_im1
        if row + 1 < m:
            U[row] = h[i]

        # RHS
        R[row] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h_im1)

    # Fix D computed above (simplify properly):
    for i in range(1, n):
        row = i - 1
        D[row] = 2 * (h[i - 1] + h[i])

    # Solve tridiagonal for interior c values
    c_interior = thomas_solve(L, D, U, R)

    # Build full c array at nodes
    c_full = np.zeros(n + 1)
    c_full[1:n] = c_interior


    a = y[:-1].copy()
    b = np.zeros(n)
    c = c_full[:-1].copy()   # interval uses c at left node
    d = np.zeros(n)

    for i in range(n):
        b[i] = (y[i + 1] - y[i]) / h[i] - (h[i] * (2 * c_full[i] + c_full[i + 1])) / 3
        d[i] = (c_full[i + 1] - c_full[i]) / (3 * h[i])

    return a, b, c, d



def eval_spline(x_data, coeffs, x_query):
    """
    Evaluate spline at x_query points.
    """
    x_data = np.asarray(x_data, dtype=float)
    x_query = np.asarray(x_query, dtype=float)
    a, b, c, d = coeffs

    n = len(x_data) - 1
    y_out = np.zeros_like(x_query, dtype=float)

    idx = np.searchsorted(x_data, x_query, side="right") - 1
    idx = np.clip(idx, 0, n - 1)

    t = x_query - x_data[idx]
    y_out = a[idx] + b[idx] * t + c[idx] * t**2 + d[idx] * t**3
    return y_out



def demo():
    # Your dataset
    x = np.array([0.0, 1.5, 3.0, 4.2, 5.0, 6.5, 8.0])
    y = np.array([0.0, 12.5, 10.0, 18.2, 15.0, 22.0, 0.0])

    # Build spline
    coeffs = natural_cubic_spline_coeffs(x, y)

    # Dense x for smooth plotting
    xd = np.linspace(x[0], x[-1], 600)
    ys = eval_spline(x, coeffs, xd)

    # Linear interpolation (piecewise straight lines)
    yl = np.interp(xd, x, y)


    deg = len(x) - 1
    p = np.poly1d(np.polyfit(x, y, deg))
    yp = p(xd)

    # Plot
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, "ro", markersize=7, label="Data points")
    plt.plot(xd, ys, "-", linewidth=2, label="Natural cubic spline (smooth)")
    plt.plot(xd, yl, "--", linewidth=2, label="Linear interpolation (corners)")
    plt.plot(xd, yp, ":", linewidth=2, label=f"Degree-{deg} polynomial (can oscillate)")

    plt.title("Cubic Spline Interpolation Demo (with comparison)")
    plt.xlabel("Time (s)")
    plt.ylabel("Velocity (m/s)")
    plt.grid(True)
    plt.legend()
    plt.show()

    # Print interval equations (nice for class)
    a, b, c, d = coeffs
    print("\nSpline pieces (each interval uses t = x - x_i):")
    for i in range(len(x) - 1):
        print(f"Interval [{x[i]:.2f}, {x[i+1]:.2f}]: "
              f"S_{i}(t)= {a[i]:.6f} + {b[i]:.6f} t + {c[i]:.6f} t^2 + {d[i]:.6f} t^3")


if __name__ == "__main__":
    demo()




    import numpy as np

def cubic_spline(x, y):
    """
    Natural Cubic Spline Interpolation
    Returns interval-wise coefficients a, b, c, d such that on [x[i], x[i+1]]:
        S_i(x) = a[i] + b[i](x-x[i]) + c[i](x-x[i])^2 + d[i](x-x[i])^3
    """
    x = np.asarray(x, dtype=float)
    y = np.asarray(y, dtype=float)

    n = len(x) - 1
    h = np.diff(x)

    # Build linear system A*c = B for spline curvature (c values)
    A = np.zeros((n + 1, n + 1))
    B = np.zeros(n + 1)

    # Natural boundary conditions: c0 = 0 and cn = 0
    A[0, 0] = 1.0
    A[n, n] = 1.0

    # Fill tridiagonal matrix
    for i in range(1, n):
        A[i, i - 1] = h[i - 1]
        A[i, i]     = 2 * (h[i - 1] + h[i])
        A[i, i + 1] = h[i]
        B[i] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1])

    # Solve for c coefficients at nodes
    c_full = np.linalg.solve(A, B)

    # Compute a, b, d for each interval
    a = y[:-1].copy()
    b = np.zeros(n)
    d = np.zeros(n)
    c = c_full[:-1].copy()

    for i in range(n):
        b[i] = (y[i + 1] - y[i]) / h[i] - (h[i] * (2 * c_full[i] + c_full[i + 1])) / 3
        d[i] = (c_full[i + 1] - c_full[i]) / (3 * h[i])

    return a, b, c, d