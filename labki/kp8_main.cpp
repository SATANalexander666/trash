#include<iostream>
#include<stdlib.h>
#include<locale.h>
using namespace std;

//Тип данных: вещественный
//Линейный двунаправленный список
//Добавить k экземпляров последнего элемента в начало списка

const double RANGE = 20;
const double eps = 0.001;

struct Data
{
	double data;
};

struct List
{
	Data key;
	List *next;
};

void _print(List *begin)
{
	List *print = begin;
	while(print)
	{
		cout << print->key.data << " -> ";
		print = print->next;
	}
	cout << endl;
}

void generate_list(List **begin, int len)
{
	*begin = new List;
	(*begin)->key.data = (rand() * RANGE / RAND_MAX);
	(*begin)->next = NULL;

	List *end = *begin;

	for (int i = 0; i < len - 1; i++)
	{
		end->next = new List;
		end = end->next;
		end->key.data = (rand() * RANGE / RAND_MAX);
		end->next = NULL;
	}
}

void add_begin(List **begin, double num)
{
	List *element = new List;
	element->key.data = num;
	element->next = *begin;
	*begin = element;
}

void add_end(List *begin, double num)
{
	List *end = begin;

	while (end->next != NULL)
		end = end->next;
	end->next = new List;
	end = end->next;
	end->key.data = num;
	end->next = NULL;
}

void del(List **begin, double num)
{
	if (*begin == NULL)
		return;

	List *t = *begin;
	if (abs(t->key.data - num) < eps)
	{
		*begin = t->next;
		delete t;
		return;
	}

	List *t1 = t;
	while (t1)
	{
		if (abs(t1->key.data - num) < eps)
		{
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}

void insert(List **begin, double num, double element)
{
	if (*begin == NULL)
		return;

	List *t = *begin;
	if (abs(t->key.data - element) < eps)
		add_begin(begin, num);

	List *t1 = t->next;
	while (t1)
	{
		if (abs(t1->key.data - element) < eps)
		{
			List *insertion = new List;
			insertion->key.data = num;
			t->next = insertion;
			insertion->next = t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
	cout << "No such element" << endl;
}

void clear(List **begin)
{
	if (*begin == NULL)
		return;

	List *p = *begin;
	List *t;

	while(p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
}

int length(List *begin)
{
	int len = 0;
	List *t = begin;

	while(t)
	{
		len++;
		t = t->next;
	}
	return len;
}

void main_action(List **begin, int k)
{
	double last_num;
	List *t = *begin;

	while (t->next != NULL)
		t = t->next;
	last_num = t->key.data;

	for (int i = 0; i < k; i++)
		add_begin(begin, last_num);
}

void menu()
{
	cout << "0 - выйти." << '\n'\
		<< "1 - сгенерировать список указанной длины." << '\n'
		<< "2 - добавить элемент в конец." << '\n'
		<< "3 - добавить элемент в начало." << '\n'
		<< "4 - удалить элемент." << '\n'
		<< "5 - вывести список." << '\n'
		<< "6 - вставить элемент a перед элементом b." << '\n'
		<< "7 - очистить список." << '\n'
		<< "8 - вывести длину списка." << '\n'
		<< "9 - добавить k раз последний элемент списка в начало." << '\n'
		<< "10 - вывести это меню." << '\n'
		<< "-----------------------------------------------------" << '\n';\
}

int main()
{
	setlocale(LC_ALL, "ru");

	List *begin = NULL;
	double double_input, a;
	int menu_input, int_input;

	menu();

	while (menu_input != 0)
	{
		cout << "Введите команду: ";
		cin >> menu_input;

		switch (menu_input)
		{
			default:
				menu();
			case 0: 
				exit(0);
			case 1: 
				cout << "Введите длину списка: ";
				cin >> int_input;
				generate_list(&begin, int_input);
				break;
			case 2:
				cout << "Введите элемент: ";
				cin >> double_input;
				add_end(begin, double_input);
				break;
			case 3:
				cout << "Введите элемент: ";
				cin >> double_input;
				add_begin(&begin, double_input);
				break;
			case 4:
				cout << "Введите элемент: ";
				cin >> double_input;
				del(&begin, double_input);
				break;
			case 5:
				cout << "Линейный список:" << '\n';
				_print(begin);
				break;
			case 6:
				cout << "Введите элемент a: ";
				cin >> double_input;
				a = double_input;
				cout << "Введите элемент b: ";
				cin >> double_input;
				insert(&begin, a, double_input);
				break;
			case 7:
				clear(&begin);
				break;
			case 8:
				cout << "Длина списка: " << length(begin) << '\n';
				break;
			case 9:
				cout << "Введите k: ";
				cin >> int_input;
				main_action(&begin, int_input);
				break;
			case 10:
				menu();
		}
		cout << "----------------------" << '\n';
	}

	return 0;
}
