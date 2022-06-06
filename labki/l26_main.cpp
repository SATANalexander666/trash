#include<iostream>
#include<time.h>
#include"deque.h"
#include"MergeSort.h"
using namespace std;

//Слияние двух стеков, деков, списков или очередей,
// упорядоченных по возрастанию, сохраняя порядок.
//Сортировка слиянием.

Deque merge_deque(Deque &d1, Deque &d2)
{
	int i = 0;
	int j = 0;
	deque_3.init();

	while (d1.size() > 0 && d2.size() > 0)
		if (d1.top() < d2.top())
			deque_3.push_back(d1.pop_front());
		else
			deque_3.push_back(d2.pop_front());

	while (i < d1.size())
		deque_3.push_back(d1.pop_front());
	while (j < d2.size())
		deque_3.push_back(d2.pop_front());

	return deque_3;
}

void deque_to_array(int *arr, Deque &d)
{
	int i = 0;
	while (d.size() != 0)
		arr[i++] = d.pop_front();
}

void array_to_deque(int *arr, int arr_size, Deque &d)
{
	for (int i = 0; i < arr_size; i++)
		d.push_back(arr[i]);
}

int main()
{
	int deque_3_size;
	int arr_1_size, arr_2_size, start_time, end_time, start_time_BS, end_time_BS;

	string path1[3] = {"Data1_1", "Data1_2", "Data1_3"};
	string path2[3] = {"Data2_1", "Data2_2", "Data2_3"};

	for (int i = 0; i < 3; i++)
	{
		cout << "Files: Data1_" << i + 1 << ", Data2_" << i + 1 << '\n'\
			<< "-------------" << '\n';

		deque_1.init();
		deque_2.init();

		data_to_deque(deque_1, path1[i]);
		arr_1_size = deque_1.size();
		int *arr_1 = new int[arr_1_size];
		int *arr_1_copy = new int[arr_1_size];

		deque_to_array(arr_1, deque_1);
		cout << "First input: ";
		for (int j = 0; j < arr_1_size; j++)
			cout << arr_1[j] << " ";
		cout << endl;
		for (int j = 0; j < arr_1_size; j++)
			arr_1_copy[j] = arr_1[j];

		data_to_deque(deque_2, path2[i]);
		arr_2_size = deque_2.size();
		int *arr_2 = new int[arr_2_size];
		int *arr_2_copy = new int[arr_2_size];

		deque_to_array(arr_2, deque_2);
		cout << "Second input: ";
		for (int j = 0; j < arr_2_size; j++)
			cout << arr_2[j] << " ";
		cout << endl;
		for (int j = 0; j < arr_2_size; j++)
			arr_2_copy[j] = arr_2[j];

		cout << "-------------" << '\n';

		start_time_BS = clock();
		MergeSort_BS(arr_1, arr_1_size);
		MergeSort_BS(arr_2, arr_2_size);
		end_time_BS = clock();

		start_time = clock();
		MergeSort(arr_1_copy, 0, arr_1_size - 1, deque_1);
		MergeSort(arr_2_copy, 0, arr_2_size - 1, deque_2);
		end_time = clock();

		cout << "First deque to merge: ";
		for (int j = 0; j < arr_1_size; j++)
			cout << arr_1[j] << " ";
		cout << endl;

		cout << "Second deque to merge: ";
		for (int j = 0; j < arr_2_size; j++)
			cout << arr_2[j] << " ";
		cout << endl;

		array_to_deque(arr_1, arr_1_size, deque_1);
		array_to_deque(arr_2, arr_2_size, deque_2);

		deque_3 = merge_deque(deque_1, deque_2);
		deque_3_size = deque_3.size();

		cout << "Result deque: ";
		deque_3.out();
		cout << "-------------" << endl;
		cout << "Size of first deque = " << arr_1_size << '\n'\
			<< "Size of second deque = " << arr_2_size << '\n'
			<< "Size of result deque = " << deque_3_size << endl;\
		cout << "-------------" << endl;
		cout << "Time of Bose-Nelson sort: " << end_time_BS - start_time_BS << '\n';
		cout << "Time of classic Merge sort with deck: " << end_time - start_time << '\n';
		cout << "-------------" << '\n';

		delete[] arr_1;
		delete[] arr_1_copy;
		delete[] arr_2;
		delete[] arr_2_copy;
	}

	return 0;
}