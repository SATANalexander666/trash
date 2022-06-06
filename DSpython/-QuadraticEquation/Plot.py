import numpy as np
import matplotlib.pyplot as plt

def build_plot(a, b, c, sol):
    x = np.linspace(-20, 20, 100)
    y = a * x ** 2 + b * x + c
    plt.grid()
    plt.plot(x, y)
    if len(sol) == 2:
        plt.scatter(sol[0], 0, color = 'orange', marker = '*')
        plt.scatter(sol[1], 0, color = 'orange', marker = '*')
    elif len(sol) == 1:
        plt.scatter(sol[0], 0, color = 'orange', marker = '*')
    