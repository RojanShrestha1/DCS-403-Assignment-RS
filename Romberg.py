import math


def f(x):
   
    return math.exp(-x) * math.sin(x)

def central_diff(f, x, h):
    return (f(x + h) - f(x - h)) / (2.0 * h)


def romberg_derivative(f, x, h0=0.1, levels=5):
    # R[k][0] = D(h0 / 2^k)
    R = [[0.0 for _ in range(levels)] for _ in range(levels)]

    for k in range(levels):
        h = h0 / (2 ** k)
        R[k][0] = central_diff(f, x, h)

        # Extrapolate
        for j in range(1, k + 1):
           
          
            factor = 4 ** j
            R[k][j] = R[k][j - 1] + (R[k][j - 1] - R[k - 1][j - 1]) / (factor - 1)

    return R, R[levels - 1][levels - 1]

def print_table(R):
    print("\nRomberg table (each row refines h):")
    for i, row in enumerate(R):
        shown = row[:i+1]
        print(f"Row {i}: " + "  ".join(f"{v:.10f}" for v in shown))

if __name__ == "__main__":
    x0 = 1.0
    h0 = 0.1
    levels = 6

    R, best = romberg_derivative(f, x0, h0=h0, levels=levels)
    print(f"Estimated derivative f'({x0}) ≈ {best}")
    print_table(R)
