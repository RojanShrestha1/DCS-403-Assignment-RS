def f(x):
    return x**3 - x - 2

def df(x):
    return 3*x**2 - 1

def newton_raphson_single(x0, tol=1e-4, max_iter=50):
    x = x0
    for i in range(max_iter):
        x_new = x - f(x) / df(x)
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    return x

def bisection(a, b, tol=1e-4, max_iter=50):
    if f(a) * f(b) >= 0:
        raise ValueError("Invalid interval: root not guaranteed")

    for i in range(max_iter):
        c = (a + b) / 2
        if abs(f(c)) < tol:
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2

def f1(x, y):
    return x**2 + y**2 - 4

def f2(x, y):
    return x - y - 1

def newton_raphson_two(x0, y0, tol=1e-4, max_iter=50):
    x, y = x0, y0

    for i in range(max_iter):
        # Jacobian components
        J11 = 2*x
        J12 = 2*y
        J21 = 1
        J22 = -1

        # Determinant of Jacobian
        detJ = J11*J22 - J12*J21
        if detJ == 0:
            raise ValueError("Jacobian determinant is zero")

        # Newton-Raphson update
        dx = (-f1(x, y)*J22 + f2(x, y)*J12) / detJ
        dy = (-J11*f2(x, y) + J21*f1(x, y)) / detJ

        x_new = x + dx
        y_new = y + dy

        if abs(x_new - x) < tol and abs(y_new - y) < tol:
            return x_new, y_new

        x, y = x_new, y_new

    return x, y
