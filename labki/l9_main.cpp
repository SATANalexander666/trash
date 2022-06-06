#include<iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int sign(int a)
{
	if (a > 0) return 1;
	else if (a < 0) return -1;
	return 0;
}

int abs(int a)
{
	if (a < 0) return -a;
	else return a;
}

int main()
{
	int i, j, l, i_1, j_1, l_1, k = 0;
	i = -22;
	j = 29;
	l = 4;
	while (k != 50)
	{
		i_1 = sign(min(i, j)) * max((i + k) % 20, (j + l) % 20);
		j_1 = abs(max(i, j)) - k * min(j, l);
		l_1 = (k - l) / (((i + j + l) * (i + j + l)) % 5 + 1);
		i = i_1;
		j = j_1;
		l = l_1;
		k++;
		if (((i + 10) * (i + 10) + (j + 10) * (j + 10) < 100) && ((i + 20) * (i + 20) + (j + 20) * (j + 20) < 100))
		{
			cout << "Done" << endl << "k = " << k << endl << "i = " << i << endl << "j = " << j << endl << "l = " << l << endl;
			return 0;
		}
	}
	cout << "Not done" << endl;
	return 0;
}