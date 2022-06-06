from scipy import integrate
import numpy as np

def f(x):
    return np.sin(x) / (x + 3.1) - 0.05

def rectangle(f, a, b):
    result = 0
    h = (b - a) / 10
    a += h / 2
    x_values = [a + step * h for step in range(10)]

    for x in x_values:
        result += h * f(x)
    return result

def trapezoid(f, a, b):
    result = 0
    h = (b - a) / 20
    x_values = [a + step * h for step in range(20)]
    for i in range(len(x_values) - 1):
        result += h * (f(x_values[i]) + f(x_values[i + 1])) / 2
    return result

def main():
    a = 0.4
    b = 1.1
    epsilon = 6

    F_1, err = integrate.quad(f, a, b)
    F_1 = round(F_1, epsilon)
    F_2 = round(rectangle(f, a, b), epsilon)
    F_3 = round(trapezoid(f, a, b), epsilon)

    abs_err_2 = round(abs(F_1 - F_2), epsilon)
    abs_err_3 = round(abs(F_1 - F_3), epsilon)
    rel_err_2 = round(abs(F_1 / F_2), epsilon)
    rel_err_3 = round(abs(F_1 / F_2), epsilon)
    
    print("F_1 = %7f" % F_1)
    print("F_2 = %7f, absolute = %7f, relative = %7f" % (F_2, abs_err_2, rel_err_2))
    print("F_3 = %7f, absolute = %7f, relative = %7f" % (F_3, abs_err_3, rel_err_3))

main()












