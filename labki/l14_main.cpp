#include<iostream>
using namespace std;

//var9
// 7 13 14 16
// 6  8 12 15
// 2  5  9 11
// 1  3  4 10 

int main()
{
	int m[9][9];
	int n;
	int i;
	int j;

	cout << "Input n: ";
	cin >> n;

	cout << endl << "Source matrix:" << endl;
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			m[i][j] = (i + 1) * 10 + j + 1;
			if (j < n && j >= 0)
				cout << m[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl << "Result vector:" << endl;
	for (int k = 1 - n; k < n; k ++)
	{
		if (k % 2)
		{
			for (i = n - 1; i >= 0; i--)
			{
				j = k + i;
				if (j >= 0 && j < n)
					cout << m[i][j] << "  ";
			}
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				j = k + i;
				if (j >= 0 && j < n)
					cout << m[i][j] << "  ";
			}
		}	
	}
	cout << endl;

	return 0;
}