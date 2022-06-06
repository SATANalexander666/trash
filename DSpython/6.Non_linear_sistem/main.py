import sympy as smp
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import fsolve

def f_1(x, y):
    return y ** 2 - (x ** 2) / 1.7 - 2.1

def f_2(x, y):
    return y + 3.2 * smp.sin(x - 4.6) - 1.3

def system(parametr):
    x, y = parametr
    return (f_1(x, y), f_2(x, y))

def unpack_roots(solution, variable):
    result = []
    for i in range(len(solution)):
        result.append(solution[i][variable])
    return result

def get_roots(epsilon, *args):
    x_roots = []
    y_roots = []
    functions = []
    x_epsilon = 0
    x0, y0 = fsolve(system, (0, 0))

    for list_of_func in args:
        for func in list_of_func:
            functions.append(func)

    for func in functions:
        x_step = 0
        period = 0
        while abs(func(abs(x0) + x_step)) < epsilon:
            x_step += 1
            period += 1
            if period > 50:
                x_step = 0
                break
        x_epsilon = max(x_epsilon, x_step)

    for x in range(x_epsilon):
        x_new, y_new = fsolve(system, (x, 0))
        if x_new not in x_roots:
            x_roots.append(round(x_new, 5))
            y_roots.append(round(y_new, 5))
        x_new, y_new = fsolve(system, (-x, 0))
        if x_new not in x_roots:
            x_roots.append(round(x_new, 5))
            y_roots.append(round(y_new, 5))

    return x_roots, y_roots

def get_functions(roots, variable):
    result = []
    for i in range(len(roots)):
        result.append(smp.lambdify(variable, roots[i]))
    return result

def build_graphics(*args):
    colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k']
    counter = 0
    x_1 = np.linspace(-10, 10, 100)
    for func in args:
        func_values = []
        for i in range(len(func)):
            func_step = [func[i](x_value) for x_value in x_1]
            func_values.append(func_step)
        for j in range(len(func_values)):
            plt.plot(x_1, func_values[j], colors[counter])
        counter += 1

def main():
    x, y = smp.symbols('x y')
    equation_1 = smp.Eq(f_1(x, y), 0)
    equation_2 = smp.Eq(f_2(x, y), 0)
    solution_1 = smp.solvers.solve(equation_1, y, dict = True)
    solution_2 = smp.solvers.solve(equation_2, y, dict = True)
    roots_1 = unpack_roots(solution_1, y)
    roots_2 = unpack_roots(solution_2, y)
    
    lam_1 = get_functions(roots_1, x)
    lam_2 = get_functions(roots_2, x)
    build_graphics(lam_1, lam_2)

    eps = int(abs(abs(lam_1[0](0)) - abs(lam_2[0](0))) * 10) + 1
    x_roots, y_roots = get_roots(eps, lam_1, lam_2)

    i = 0
    while i < len(x_roots):
        if x_roots.count(x_roots[i]) > 1:
            x_roots.pop(i)
            y_roots.pop(i)
        i += 1

    for i in range(len(x_roots)):
        print("x%1d = %5f, y%1d = %5f" %(i, x_roots[i], i, y_roots[i]))
    plt.plot(x_roots, y_roots, 'or')
    plt.grid()
    plt.show()

main()








