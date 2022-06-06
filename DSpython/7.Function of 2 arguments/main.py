import numpy as np
import matplotlib.pyplot as plt

def f(x, y):
    return (2.3 * x ** 2 + 4.1 * (y - 3.5) ** 2) ** 0.4

def get_f(f, x, y):
    result = []
    for i in range(len(x)):
        f_dim = []
        for j in range(len(x[0])):
            f_dim.append(f(x[i][j], y[i][j]))
        result.append(f_dim)
    return np.array(result)

def get_min_f(f_1, x_1, y_1, delta):
    f_min = 9999
    for i in range(len(f_1)):
        for j in range(len(f_1[0])):
            if f_min > f_1[i][j]:
                f_min = f_1[i][j]
                x_min = x_1[i][j]
                y_min = y_1[i][j]
    accurate_minimum = [x_min, y_min, f_min]
    x_2, y_2 = np.meshgrid(np.linspace(x_min - delta, x_min + delta, 100), 
            np.linspace(y_min - delta, y_min + delta, 100))
    f_2 = get_f(f, x_2, y_2)
    return x_2, y_2, f_2, accurate_minimum
    


def main():
    delta = 0.1
    x_grid, y_grid = np.meshgrid(np.linspace(-10, 10, 100), 
            np.linspace(-10, 10, 100))
    f_grid = get_f(f, x_grid, y_grid)
    x_min, y_min, f_min, ac_min = get_min_f(f_grid, x_grid, y_grid, delta)

    '''
    fig = plt.figure()
    ax = fig.add_subplot(projection = '3d')
    ax.plot_surface(x_grid, y_grid, f_grid, cmap = 'inferno')
    ax.plot_surface(x_min, y_min, f_min, color = 'w')
    '''

    print("Minimal Value: Coordinates: x = %5f, y = %5f, Value: f(x, y) = %5f" 
        % (ac_min[0], ac_min[1], ac_min[2]))
    plt.contour(x_grid, y_grid, f(x_grid, y_grid))
    plt.contour(x_min, y_min, f(x_min, y_min))
    #plt.contourf(x_grid, y_grid, f(x_grid, y_grid))
    plt.show()


main()









