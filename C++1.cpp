#include <iostream>
#include <locale>
using namespace std;

int func(int* arr, int length, int number)
{
	int z = 0, min = arr[0], max = 0;


	for (size_t i = 0; i < length; i++)// знаходимо максимальний елемент масиву
	{
		if (arr[i] > max)
			max = i;
	}

	for (size_t i = 0; i < length; i++)// знаходимо мінімальний елемент масиву
	{
		if (arr[i] < min)
			min = i;
	}

	for (int i = min; i < max; i++)
	{
		if (arr[i] == number) //знаходження кількості входжень числа
		{
			z++;
		}
	}
	return z;
}

int func(char* str, char ch)
{
	cout << "Введите начальную точку (символ) - ";
	int z = 0, p, k;
	cin >> p;
	cout << endl << "Введите конечную точку (символ) - ";
	cin >> k;
	for (int i = p; i < k; i++)
	{
		if (str[i] == ch) //знаходження кількості входжень символу
		{
			z++;
		}
	}
	return z;
}

//int func(char* str, char ch, char, char)
//{
//	int z = 0;
//	for (int i = 0; i < strlen(str); i++)
//	{
//		if (str[i] == ch) 
//		{
//			z++;
//		}
//	}
//	return z;
//}

void main()
{
	setlocale(LC_ALL, "Rus");
	static int chis;
	cout << "Введите число - ";
	cin >> chis;
	cout << endl;
	char bukv;
	cout << "Введите символ - ";
	cin >> bukv;
	cout << endl;
	//***********************************
	const int size = 9; //Розмір масиву*
	//***********************************
	register int arr[size] = { 1, 1, 2, 1, 1, 5,5,5,5 };
	for (int i = 0; i < size; i++) //Генерує рандомні числа для першої функції
	{
		//arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Количество чисел: " << func(arr, size, chis) << endl;

	register char str[size];

	for (int i = 0; i < size; i++) //Генерує рандомні числа для другої функції
	{
		str[i] = 97 + rand() % 25;
		cout << str[i] << " ";
	}
	cout << endl;
	cout << "Количество символов: " << func(str, bukv) << endl;
}