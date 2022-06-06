import numpy as np
import matplotlib.pyplot as plt 

def relative_error(x, y, f):
    result = 0
    for i in range(len(x)):
        result += abs((y[i] - f[i]) / y[i])
    return (result / len(x)) * 100  

def main():
    x = np.array([0.8, 0.9, 1.9, 4, 3.4, 5.6, 5.7])
    y = np.array([0.72, 0.48, 0.85, -0.76, -0.06, -0.93, -0.45])
    
    x_1 = np.linspace(min(x), max(x), 100)
    f = np.poly1d(np.polyfit(x, y, 2))
    f_values = [f(a) for a in x]

    print(relative_error(x, y, f_values))

    plt.plot(x, y, 'o')
    plt.plot(x_1, f(x_1))
    plt.grid()
    plt.show()

main()













