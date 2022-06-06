#include<iostream>

void short_out(int *M, double *A, int len, int not_zero)
{
    std::cout << "Short form of matrix:" << '\n';
    for (int i = 0; i < len; i++)
        std::cout << M[i] << " ";
    std::cout << '\n';
    for (int i = 0; i < 2 * not_zero; i++)
        std::cout << A[i] << " " << '\n';
}

void full_out(double **M, int n, int m)
{
    std::cout << "Full form of matrix:" << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << M[i][j] << " ";
        std::cout << '\n';
    }
    std::cout << '\n';
}

void short_to_full(double **matrix, int *M, double *A, int len, int not_zero) 
{
    int start, end, cur, i, j, lastInd;
    for (i = 0; i < len; i++) 
    {
        if (M[i] == 0) 
            continue;
        start = M[i];
        lastInd = i - (1 * M[i] == 0);

        for (cur = i + 1; (cur < len - 1) && (M[cur] == 0); cur++); 

        end = M[cur];
        for (j = start - 1; j < end - 1; j++)
        {
            matrix[i][int(A[j])] = A[j + 1];
            ++j;
        }
    }

    for (j = M[lastInd]-1; j < 2 * not_zero; j++) 
    {
        matrix[lastInd][int(A[j])] = A[j + 1];
        j++;
    }

}

void find_vector(double **matrix, int n, int m)
{
    int not_zero_max = 0, not_zero = 0, cur_column = 0, prev_column = 0;
    double multiply = 1;

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] != 0)
                not_zero++;
        }
        if (not_zero >= not_zero_max)
        {
            if (not_zero == not_zero_max)
                prev_column = cur_column;
            else
                prev_column = j;
            not_zero_max = not_zero;
            cur_column = j;
        }
    }

    for (int i = 0; i < n; i++)
        multiply *= matrix[i][prev_column];

    std::cout << "Multiplication: " << multiply << ", Column: " << prev_column << '\n'; 
}   

void full_to_short(double **matrix, int *M, double *A, int cntNz, int n, int m) 
{ 
    for (int i = 0; i < n; ++i) 
        M[i] = 0;

    for (int i = 0; i < cntNz * 2; ++i)
        A[i] = 0;

    int cnt = 0, zero = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (matrix[i][j] != 0) 
            {
                if (!zero) 
                {
                    M[i] = cnt + 1;
                    zero = 1;
                }
                A[cnt++] = j;
                A[cnt++] = matrix[i][j];
            }
        }
        zero = 0;
    }
}

int main() 
{
    double *A, **matrix;
    int *M, not_zero, n, m;
    int int_input;
    double double_input;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &not_zero);

    matrix = new double *[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new double[m];

    M = new int[n];
    A = new double[3 * not_zero];

    for (int i = 0; i < n; ++i) 
        scanf("%d", &M[i]);

    for (int i = 0; i < 2 * not_zero; ++i) 
        scanf("%f", &A[i]);

    f.close();

    short_out(M, A, n, not_zero);
    short_to_full(matrix, M, A, n, not_zero);
    full_out(matrix, n, m);
    full_to_short(matrix, M, A, not_zero, n, m);
    short_out(M, A, n, not_zero);
    find_vector(matrix, n, m);

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}