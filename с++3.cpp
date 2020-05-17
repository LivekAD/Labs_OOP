#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

// заполнение массива единицами
void fill_array_one(int**, size_t);
// заполнение массива по схеме
void fill_array_scheme(int**, size_t);
// печать массива
void print_array(int**, size_t);


int main() {
	setlocale(LC_ALL, "Rus");
	size_t dimm;
	int** my_arr;


	cout << "Введите размерность квадратной матрицы" << endl;
	cin >> dimm;

	my_arr = new int* [dimm];

	for (size_t i = 0; i < dimm; i++)
		my_arr[i] = new int[dimm];

	cout << "Квадратная матрица заполнена единицами" << endl;
	fill_array_one(my_arr, dimm);
	print_array(my_arr, dimm);

	cout << "Квадратная матрица заполнена по схеме" << endl;
	fill_array_scheme(my_arr, dimm);
	print_array(my_arr, dimm);

	for (size_t i = 0; i < dimm; i++)
		delete[] my_arr[i];

	delete[] my_arr;

	return 0;
}

void fill_array_one(int** arr, size_t n) {
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < n; ++j)
			arr[i][j] = 1;
}

void fill_array_scheme(int** arr, size_t n) {
	for (int i = 0; i < (n / 2); i++)
	{
		for (int j = 0; j < (n / 2 - i); j++)
		{
			arr[i][j] = 0;
		}

		if(n % 2 == 1)
			for (int j = (n / 2 + i + 1); j < n; j++)
			{
				arr[i][j] = 0;
			}
		if (n % 2 == 0)
			for (int j = (n / 2 + i); j < n; j++)
			{
				arr[i][j] = 0;
			}
	}
	
	int k = 1, z = 0, m = n;

	while (m > 0)
	{
		m = m - 2;
		z++;
	}
	
	if (n % 2 == 1) {
		for (int i = (n / 2 + 1); i < n; i++)
		{
			for (int j = 0; j < (i - z + 1); j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	if (n % 2 == 0)
	{
		for (int i = (n / 2); i < n; i++)
		{
			for (int j = 0; j < (i - z + 1); j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	
	if (n % 2 == 1) {
		for (int i = n - 1; i >= (n / 2 + 1); i--)
		{
			for (int j = n / 2 + 1; j <= n - 1; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	if (n % 2 == 0) {
		for (size_t i = n/2; i < n; i++)
		{
			for (size_t j = n/2; j < n; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	if (n % 2 == 1) {
		for (int i = n / 2 + 1, p = 1; i <= n - 1, p <= n - 1; i++, p++)
		{

			for (int j = n / 2; j < (n - p); j++)
			{
				arr[i][j] = 1;
			}

		}
	}

	if (n % 2 == 0)
	{
		for (int i = n / 2, p = 1; i <= n - 1, p <= n - 1; i++, p++)
		{

			for (int j = n / 2; j < (n - p); j++)
			{
				arr[i][j] = 1;
			}

		}
	}
}

void print_array(int** array, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j)
			cout << setw(2) << array[i][j];
		cout << endl;
	}
}