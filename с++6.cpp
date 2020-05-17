#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Kos
{
public:
	int n = 3;
	int* p = new int[n];
	int size = 5;
	int price = 1550;
	string name = "Костюм";
};

class AKos : public Kos
{
public:
	string edit = "Военный ";
	int sizel = 10;
	int* l = new int[n];
	int price = 55000;
};



int main()
{
	setlocale(LC_ALL, "Rus");
	int i;
	Kos j;
	AKos jj;
	for (i = 0; i < j.n; i++) 
	{
		cin >> j.p[i];
		jj.l[i] = j.p[i] - 3;
		if (jj.l[i] < 0)
		{
			jj.l[i] = 0;
		}
	}
	cout << jj.name << " -> " << jj.edit << jj.name << endl;
	for (size_t i = 0; i < j.n; i++)
	{
		cout << j.p[i] << " -> ";
		jj.l[i] += j.p[i];
		cout << jj.l[i] << endl;
	}
	cout << j.price << " -> " << jj.price << endl;
	return 0;
}