#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct student
{
    string surname;
    string initials;
    string letter;
};
student arr[512];

int main()
{
    setlocale(LC_ALL, "ru");
    string path_in;
    string path_out;
    cin >> path_in;
    cin >> path_out;
    fstream f;
    f.open(path_in, fstream::in);

    string input;
    int i, j = 0;
    bool first_out = 0;
    int counter = 0;

    if (!f.is_open())
    {
        cout << "Ошибка" << endl;
        return 0;
    }
    else
    {
        while(!f.eof())
        {
            input = "";
            f >> input;
            if (j % 3 == 0)
                arr[i].surname = input;
            if (j % 3 == 1)
                arr[i].initials = input;
            if (j % 3 == 2)
            {
                arr[i].letter = input;
                i++;
            }
            j++;
        }
    }
    f.close();

    f.open(path_out, fstream::out);

    if (!f.is_open())
    {
        cout << "Ошибка" << endl;
        return 0;
    }
    else
    {
        int found[i];
        for (int k = 0; k < i - 1; k++)
        {
            first_out = 0;
            for (int n = k + 1; n < i; n++)
            {
                if (arr[k].surname == arr[n].surname && arr[k].letter != arr[n].letter && found[k] != 1 && found[n] != 1)
                {
                    if (first_out == 0)
                    {
                        f << arr[k].surname << " " << arr[k].initials << " " << arr[k].letter << endl;
                        first_out = 1;
                        counter++;
                    }
                    found[n] = 1;
                    f << arr[n].surname << " " << arr[n].initials << " " << arr[n].letter << endl;
                }
            }
        }
    }
    cout << "В " << path_in << " " << counter << " групп однофамильцев." << endl;

    f.close();
    return 0;
}