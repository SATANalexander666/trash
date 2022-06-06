import numpy as np

def spline(x_values, y):
    functions = []
    for i in range(len(x_values) - 1):
        M = np.array([[x_values[i], 1], [x_values[i + 1], 1]])
        V = np.array([y[i], y[i + 1]])
        functions.append(np.linalg.solve(M, V))
    return functions

def spline_values(x_values, x, functions):
    for i in range(len(x_values) - 1):
        if x_values[i] <= x <= x_values[i + 1]:
            return functions[i][0] * x + functions[i][1]