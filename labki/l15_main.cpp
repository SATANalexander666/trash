#include<stdlib.h>
#include<iostream>
using namespace std;

int** create_matrix(int n)
{
	int **A;
	A = new int *[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[n];
	return A;
}

void clear_memory(int** A, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete [] A[i];
	}
	delete [] A;
}

int main()
{
	int **a;
	int n, i, j, shift_size, last;
	cout << "Input size of matrix: ";
	cin >> n;
	cout << "Input shift value: ";
	cin >> shift_size;
	if (shift_size < 0)
		shift_size += n * n;
	a = create_matrix(n);
	cout << endl << "Start matrix:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
			if (a[i][j] < 10)
				cout << a[i][j] << "   ";
			else
				cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	for (int count = 0; count < shift_size; count++)
	{
		if (shift_size == 0 or shift_size % (n * n) == 0)
			break;
		else
		{
			last = a[n - 1][n - 1];
			for (i = n - 1; i >= 0; i--)
			{
				for (j = n - 1; j > 0; j--)
					a[i][j] = a[i][j - 1];
				if (i > 0)
					a[i][0] = a[i - 1][n - 1];
			}
		a[0][0] = last;
		}
	}
	cout << endl << "Final matrix:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
	clear_memory(a, n);
	return 0;
}