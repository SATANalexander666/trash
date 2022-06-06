from random import randint

def create_matrix(lines, columns):
    matrix = []
    for i in range(lines):
        matrix.append([])
    for i in range(lines):
        for j in range(columns):
            matrix[i].append([])
    return matrix

def generate_matrix(a):
    for i in range(len(a)):
        for j in range(len(a[0])):
            a[i][j] = randint(0, 10)
    return a

def print_matrix(a):
    if type(a) is list:
        for line in a:
            for element in line:
                print(element, end = ' ')
            print()
        print()
        
def create_equal(a):
    b = create_matrix(len(a), len(a[0]))
    for i in range(len(a)):
        for j in range(len(b)):
            b[i][j] = a[i][j]
    return b

def multiply_matrix(a, b):
    if type(b) is not(list):
        for line in a:
            for element in line:
                element *= b
        return a
    if type(a) is not(list):
        for line in b:
            for element in line:
                element *= a
        return b
    if len(b)!=len(a[0]):
        print("Матрицы не могут быть перемножены")
        return 0        
    else:
        s = 0   
        c = []
        res_matrix = []
        for k in range(0, len(a)):
            for j in range(0, len(b[0])):
                for i in range(0, len(a[0])):
                   s += a[k][i] * b[i][j]
                c.append(s)
                s = 0
            res_matrix.append(c)
            c = []           
    return res_matrix

def transpose_matrix(a):
    if type(a) is list:
        matrix = create_matrix(len(a[0]), len(a))
        for i in range(len(a)):
            for j in range(len(a[0])):
                matrix[j][i] = a[i][j]
        return matrix
    
def det_matrix(a):
    if type(a) is list:
        if len(a) > 2:
            det = 0
            for i in range(len(a)):
                c = create_equal(a)
                c.pop(0)
                c = transpose_matrix(c)
                c.pop(i)
                c = transpose_matrix(c)
                det += (-1) ** i * a[0][i] * det_matrix(c)
            return det
        else:
            return a[0][0] * a[1][1] - a[0][1] * a[1][0]
        
def united_matrix(a):
    if type(a) is list:
        if len(a) > 2:
            b = create_matrix(len(a), len(a))
            for i in range(len(a)):
                for j in range(len(a)):
                    c = create_equal(a)
                    c.pop(i)
                    c = transpose_matrix(c)
                    c.pop(j)
                    c = transpose_matrix(c)
                    b[i][j] = (-1) ** (i + j) * det_matrix(c)
        else:
            return a[0][0] * a[1][1] - a[0][1] * a[1][0]
    return b
            
def inversed_matrix(a):
    det = det_matrix(a)
    a_1 = transpose_matrix(a)
    a_2 = united_matrix(a_1)
    for i in range(len(a_2)):
        for j in range(len(a_2[0])):
            a_2[i][j] *= 1 / det
    return a_2
        
        
        
        
        
        