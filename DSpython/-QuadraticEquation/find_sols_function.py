def find_sols(a, b, c, sol):
    d = b ** 2 - 4 * a * c
    if d == 0:
        sol.append(-b / (2 * a))
    elif d > 0:
        sol.append((-b - d ** 0.5) / (2 * a))
        sol.append((-b + d ** 0.5) / (2 * a))