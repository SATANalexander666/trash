import numpy as np
import matplotlib.pyplot as plt
from Linear_spline import spline, spline_values
from LaCringe_polynomial import lagranz

def main():
    x = np.array([1, 2, 3, 4, 5, 6], dtype = float)
    y = np.array([1.57, 2.87, -1.08, 1.02, -1.78, 1.95], dtype = float)

    x_1 = np.linspace(np.min(x), np.max(x), 500)
    y_1 = [lagranz(x, y, i) for i in x_1]

    spline_functions = spline(x, y)
    y_2 = [spline_values(x, point, spline_functions) for point in x_1]

    plt.plot(x, y, 'o', x_1, y_1)
    plt.plot(x_1, y_2)
    plt.grid(True)
    plt.show()

main()