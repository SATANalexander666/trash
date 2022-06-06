#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void heapify(vector<double>& arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) 
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heap_sort(vector<double>& arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

double bin_search(vector<double>& arr, int len, double key)
{
	double eps = 0.00001;
	int l = 0;
	int r = len - 1;
	int mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (abs(arr[mid] - key) < eps)
			return mid;
		if (key > arr[mid])
			l = mid;
		if (key < arr[mid])
			r = mid;
	}
	return -1;
}

void reverse(vector<double>& arr, int len)
{
	for (int i = 0; i < len / 2; i++)
		swap(arr[i], arr[len - 1 - i]);
}

int main()
{
	double input;
	double index;
	double key;
	int len = 0;
	bool flag = 0;
	bool sorted = 1;
	string command = "";
	string path = "";
	vector<double> nums;

	cout << "Введите имя файла для чтения" << endl;
	cin >> path;

	setlocale(LC_ALL, "ru");
	fstream f;
	f.open(path, fstream::in);

	if (!f.is_open())
		cout << "Error" << endl;
	else
		while (!f.eof())
		{
			f >> input;
			nums.push_back(input);
			len++;
		}
	f.close();

	if (len <= 2)
	{
		cout << "Файл пуст" << endl;
		return 0;
	}
	else
		while (command != "quit")
		{
			if (flag == 0)
			{
				cout << "Введите menu, чтобы открыть меню" << '\n';
				flag = 1;
			}

			if (command == "menu")
				cout << "------------------------------------------" << '\n'\
					<< "print - вывести массив" << '\n'
					<< "sort - отсортировать массив" << '\n'
					<< "search - бинарный поиск ключа в массиве" << '\n'
					<< "reverse - развернуть массив" << '\n'
					<< "index - вывести элемент массива по индексу" << '\n'
					<< "check_sort - проверить отсортированность массива" << '\n'
					<< "quit - равершить работу программы" << '\n'
					<< "------------------------------------------" << '\n';\

			command = "";
			cin >> command;

			if (command == "print")
				for(int i = 0; i < len; i++)
					cout << nums[i] << endl;

			if (command == "sort")
				heap_sort(nums, len);

			if (command == "reverse")
				reverse(nums, len);

			if (command == "search")
			{
				key = 0;
				cin >> key;
				index = bin_search(nums, len, key);
				if (index == -1)
					cout << "No such number" << endl;
				else
					cout << index << endl;
			}

			if (command == "index")
			{
				index = 0;
				cin >> index;
				cout << nums[index] << endl;
			}

			if (command == "check_sort")
			{
				sorted = 1;
				for (int i = 0; i < len - 2; i++)
				{
					if (nums[i] > nums[i + 1])
					{
						cout << "Массив не отсортирован" << '\n';
						sorted = 0;
						break;
					}
				}
				if (sorted == 1)
					cout << "Массив отсортирован" << '\n';

			}

			cout << "------------------------------------------" << '\n';
		}

	return 0;
}