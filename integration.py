
def f(x):
    return 0.2 + 25*x - 200*x**2 + 675*x**3 - 900*x**4 + 400*x**5


def trapezoid(a, b, n):
    h = (b - a) / n
    s = f(a) + f(b)

    for i in range(1, n):
        x = a + i*h
        s = s + 2*f(x)

    I = (h/2) * s
    return I


def simpson(a, b, n):
    # n must be even
    if n % 2 != 0:
        print("Simpson 1/3 rule needs EVEN n (2,4,6,8...)")
        return None

    h = (b - a) / n
    s = f(a) + f(b)

    for i in range(1, n):
        x = a + i*h
        if i % 2 == 1:
            s = s + 4*f(x)
        else:
            s = s + 2*f(x)

    I = (h/3) * s
    return I


print("NUMERICAL INTEGRATION")
print("1. Composite Trapezoidal Rule")
print("2. Composite Simpson's 1/3 Rule")

choice = int(input("Enter choice (1 or 2): "))
a = float(input("Enter lower limit a: "))
b = float(input("Enter upper limit b: "))
n = int(input("Enter number of segments n: "))

if choice == 1:
    ans = trapezoid(a, b, n)
    print("Result =", ans)

elif choice == 2:
    ans = simpson(a, b, n)
    if ans is not None:
        print("Result =", ans)

else:
    print("Invalid choice")
