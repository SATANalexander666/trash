#from math import acos
import lapy as lp

def print_vector(a):
    print(a[0], 'i + ', a[1], 'j + ', a[2], 'k', end='')
    print()
    
def create_vector(a, b):
    c = []
    for i in range(len(a)):
        c.append(b[i] - a[i])
    return c

def vector_length(a):
    length = 0
    for coordinate in a:
        length += coordinate ** 2
    return length ** 0.5

def scalar_multiplication(a, b):
    result = 0
    for i in range(len(a)):
        result += a[i] * b[i]
    return result

def angle_between(a, b):
    result = scalar_multiplication(a, b) / (vector_length(a) * vector_length(b))
    return result
        
def vector_multiplication(a, b):
    d = []
    for i in range(len(a)):
        c = [a, b]
        c = lp.transpose_matrix(c)
        c.pop(i)
        c = lp.transpose_matrix(c)
        det = c[0][0] * c[1][1] - c[1][0] * c[0][1]
        d.append((-1) ** i * det)
    return d

def mixed_multiplication(a, b, c):
    d = []
    for i in range(len(a)):
        e = [b, c]
        e = lp.transpose_matrix(e)
        e.pop(i)
        e = lp.transpose_matrix(e)
        det = a[i] * (e[0][0] * e[1][1] - e[1][0] * e[0][1])
        d.append((-1) ** i * det)
    return d

def general(a, b, c)



