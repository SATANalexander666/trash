def lagranz(x, y, t):
    result = 0
    for j in range(len(y)):
        numerator = 1
        denominator = 1
        for i in range(len(x)):
            if i != j:
                numerator *= (t - x[i])
                denominator *= (x[j] - x[i])
        result += y[j] * (numerator / denominator)
    return result