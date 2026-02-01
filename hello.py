from bisect import bisect_right
import math


class NaturalCubicSpline:
    """
    Natural cubic spline interpolation.

    - Requires x strictly increasing.
    - Natural boundary conditions: S''(x0)=0 and S''(xn)=0
    """

    def __init__(self, x, y):
        if len(x) != len(y):
            raise ValueError("x and y must have the same length.")
        if len(x) < 2:
            raise ValueError("Need at least two data points.")
        if any(x[i] >= x[i + 1] for i in range(len(x) - 1)):
            raise ValueError("x must be strictly increasing (no duplicates).")

        self.x = list(x)
        self.y = list(y)
        self.n = len(x)

        # If only two points, spline reduces to straight line
        if self.n == 2:
            h = self.x[1] - self.x[0]
            self.a = [self.y[0]]
            self.b = [(self.y[1] - self.y[0]) / h]
            self.c = [0.0]
            self.d = [0.0]
            return

        self._build()

    def _build(self):
        n = self.n
        x, y = self.x, self.y


        h = [x[i + 1] - x[i] for i in range(n - 1)]


        m = n - 2  # number of unknown interior second-derivatives

        A = [0.0] * m
        B = [0.0] * m
        C = [0.0] * m
        D = [0.0] * m

        for i in range(1, n - 1):
            row = i - 1
            A[row] = h[i - 1]
            B[row] = 2.0 * (h[i - 1] + h[i])
            C[row] = h[i]
            slope_next = (y[i + 1] - y[i]) / h[i]
            slope_prev = (y[i] - y[i - 1]) / h[i - 1]
            D[row] = 6.0 * (slope_next - slope_prev)


        M_interior = self._thomas(A, B, C, D)

        # Full M array
        M = [0.0] + M_interior + [0.0]


        a = [0.0] * (n - 1)
        b = [0.0] * (n - 1)
        c = [0.0] * (n - 1)
        d = [0.0] * (n - 1)

        for i in range(n - 1):
            hi = h[i]
            a[i] = y[i]
            b[i] = (y[i + 1] - y[i]) / hi - hi * (2.0 * M[i] + M[i + 1]) / 6.0
            c[i] = M[i] / 2.0
            d[i] = (M[i + 1] - M[i]) / (6.0 * hi)

        self.a, self.b, self.c, self.d = a, b, c, d

    @staticmethod
    def _thomas(a, b, c, d):
        """
        Solve tridiagonal system using Thomas algorithm.
        a, b, c are the sub-, main-, super-diagonals (same length m)
        d is RHS (length m)

        Note: Here a[0] and c[m-1] are allowed to be non-zero,
        but effectively at the boundaries they won't reference outside unknowns.
        """
        m = len(d)
        if m == 0:
            return []


        cp = [0.0] * m
        dp = [0.0] * m


        denom = b[0]
        if abs(denom) < 1e-15:
            raise ZeroDivisionError("Tridiagonal solve failed: near-zero pivot.")

        cp[0] = c[0] / denom
        dp[0] = d[0] / denom

        for i in range(1, m):
            denom = b[i] - a[i] * cp[i - 1]
            if abs(denom) < 1e-15:
                raise ZeroDivisionError("Tridiagonal solve failed: near-zero pivot.")
            cp[i] = c[i] / denom if i < m - 1 else 0.0
            dp[i] = (d[i] - a[i] * dp[i - 1]) / denom


        x = [0.0] * m
        x[m - 1] = dp[m - 1]
        for i in range(m - 2, -1, -1):
            x[i] = dp[i] - cp[i] * x[i + 1]
        return x

    def _interval_index(self, xq):
        """
        Return i such that x[i] <= xq <= x[i+1], clamped to range.
        """
        if xq <= self.x[0]:
            return 0
        if xq >= self.x[-1]:
            return self.n - 2
        return bisect_right(self.x, xq) - 1

    def evaluate(self, xq):
        """
        Evaluate spline at xq (scalar or iterable).
        Extrapolates by clamping to first/last interval.
        """
        if isinstance(xq, (list, tuple)):
            return [self._eval_one(v) for v in xq]
        return self._eval_one(xq)

    def _eval_one(self, xq):
        i = self._interval_index(xq)
        t = xq - self.x[i]
        return self.a[i] + self.b[i] * t + self.c[i] * t * t + self.d[i] * t * t * t

    def derivative(self, xq):
        """First derivative S'(xq)."""
        i = self._interval_index(xq)
        t = xq - self.x[i]
        return self.b[i] + 2.0 * self.c[i] * t + 3.0 * self.d[i] * t * t

    def second_derivative(self, xq):
        """Second derivative S''(xq)."""
        i = self._interval_index(xq)
        t = xq - self.x[i]
        return 2.0 * self.c[i] + 6.0 * self.d[i] * t

def assert_close(a, b, tol=1e-10, msg=""):
    if abs(a - b) > tol:
        raise AssertionError(f"{msg} | {a} vs {b} (tol={tol})")


def test_passes_through_knots():
    x = [0, 1, 2, 3, 4]
    y = [0, 1, 0, 1, 0]
    sp = NaturalCubicSpline(x, y)
    for xi, yi in zip(x, y):
        sxi = sp.evaluate(xi)
        assert_close(sxi, yi, tol=1e-12, msg="Spline does not pass through knot")
    print("test_passes_through_knots passed")


def test_smoothness_at_internal_knots():

    x = [0.0, 0.7, 1.4, 2.0, 3.2]
    y = [1.0, 0.2, 1.5, 1.0, 2.2]
    sp = NaturalCubicSpline(x, y)

    for i in range(1, len(x) - 1):
        knot = x[i]

        eps = 1e-9
        left = sp.derivative(knot - eps)
        right = sp.derivative(knot + eps)
        assert_close(left, right, tol=1e-6, msg=f"C1 continuity failed at knot i={i}")
    print("test_smoothness_at_internal_knots passed")


def test_sin_accuracy_demo():

    x = [0.0, math.pi / 4, math.pi / 2, 3 * math.pi / 4, math.pi]
    y = [math.sin(v) for v in x]
    sp = NaturalCubicSpline(x, y)


    max_err = 0.0
    for k in range(101):
        xx = (math.pi * k) / 100.0
        err = abs(sp.evaluate(xx) - math.sin(xx))
        if err > max_err:
            max_err = err

    print(f"test_sin_accuracy_demo done | max error ~ {max_err:.6e}")


if __name__ == "__main__":

    test_passes_through_knots()
    test_smoothness_at_internal_knots()
    test_sin_accuracy_demo()


    x_data = [0, 1, 2, 3]
    y_data = [1, 2, 0, 2]
    spline = NaturalCubicSpline(x_data, y_data)

    x_query = 1.5
    print(f"S({x_query}) = {spline.evaluate(x_query)}")
