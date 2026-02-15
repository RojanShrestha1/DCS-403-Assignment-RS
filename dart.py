import random
import math

def f(x):
    return math.sin(x) - 0.5   # replace with Prob 22.20 function

def estimate_y_bounds_include_zero(f, a, b, samples=2000, pad_ratio=0.05):
    ys = []
    for i in range(samples):
        x = a + (b - a) * i / (samples - 1)
        ys.append(f(x))
    y_min = min(ys)
    y_max = max(ys)

    # IMPORTANT: include y=0 in the rectangle
    y_min = min(y_min, 0.0)
    y_max = max(y_max, 0.0)

    # pad a bit
    pad = (y_max - y_min) * pad_ratio if y_max != y_min else 1.0
    return y_min - pad, y_max + pad

def mc_dartboard_integral_fixed_bounds(f, a, b, N, y_min, y_max, seed=0):
    random.seed(seed)
    rect_area = (b - a) * (y_max - y_min)

    pos_hits = 0
    neg_hits = 0

    for _ in range(N):
        x = random.uniform(a, b)
        y = random.uniform(y_min, y_max)
        fx = f(x)

        if fx > 0 and (0 < y < fx):
            pos_hits += 1
        elif fx < 0 and (fx < y < 0):
            neg_hits += 1

    return rect_area * (pos_hits - neg_hits) / N

def derivative_of_integral_dartboard_strip(f, b, h=0.01, N=300000, seed=123):
    a = b
    c = b + h

    y_min, y_max = estimate_y_bounds_include_zero(f, a, c)
    small_integral = mc_dartboard_integral_fixed_bounds(f, a, c, N, y_min, y_max, seed=seed)

    return small_integral / h

if __name__ == "__main__":
    b = 2.0
    h = 0.01
    N = 500000

    est = derivative_of_integral_dartboard_strip(f, b, h=h, N=N)
    print("Estimated dI/db (strip dartboard) =", est)
    print("True f(b) =", f(b))
