import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import root

def f(x):
    return (x ** 2) * np.sin(4.6 * x) - 1

def bisection(f, left_border, right_border, eps):
    result = []
    step = 0.1
    steps = [left_border + step * i for i in 
        range(int(abs((left_border - right_border) / step)))]

    for i in range(len(steps) - 1):
        a = steps[i]
        b = steps[i + 1]
        if f(a) * f(b) < 0:
            while abs(f(b) - f(a)) > eps:
                c = (a + b) / 2
                if f(a) * f(c) > 0:
                    a = c
                else:
                    b = c
            if len(result) > 0:
                if abs(c - result[-1]) > eps:
                    result.append(c)
            else:
                result.append(c)
    return result
     
def roots(f, a, b):
    result = []
    steps = [a + i * 0.5 for i in range(int(abs(a - b) / 0.5) + 1)]
    for step in steps:
        x = root(f, step).x
        if np.isclose(f(x), 0):
            if a <= x <= b and x not in result:
                result.append(x)
    return result

def main():
    a = -3
    b = 5
    epsilon = 0.000001

    x_1 = np.linspace(a, b, 1000)
    y_1 = [f(x) for x in x_1]

    '''
    x_2 = [x for x in x_1 if abs(f(x)) < epsilon]
    y_2 = [0 for each in x_2]
    plt.plot(x_2, y_2, '*')
    print(x_2)
    '''

    x_3 = (bisection(f, a, b, epsilon))
    y_3 = [0 for x in x_3]
    #plt.plot(x_3, y_3, 'o')

    x_4 = roots(f, a, b)
    y_4 = [0 for each in x_4]
    plt.plot(x_4, y_4, 'o')
    
    plt.plot(x_1, y_1)
    plt.grid()
    plt.show()

    bisection_roots = (bisection(f, a, b, epsilon))
    for i in range(len(bisection_roots)):
        print("x%1d = %5f" %(i + 1, bisection_roots[i]))

main()










