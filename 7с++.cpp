#include <locale>
#include <iostream>
#include <string>


using namespace std;

class CDevice
{
private:
	int n = 2;
	int* ID = new int[n];
public:
	CDevice()
	{
		for (int i = 0; i < n; i++)
		{
			ID[i] = rand() % 8;
		}
	}

	virtual void ShowDevice()
	{
		cout << "Готово IDmouse - " << ID[0] << " " << "IDKeyboard - " << ID[1] << endl;
	}

	~CDevice()
	{
		delete[] ID;
	}
};

class CKeyboard : public CDevice
{
private:
	string keybName = "A4Tech";
	string keyb = "12.04.2017";
public:
	void ShowDevice() override
	{
		cout << "Клавиатура подключена!" << endl;
	}

	int key()
	{
		int ccc, kk;
		ccc = rand() % 2;
		if (ccc == 1)
		{
			cout << "Вы хотите включить залипание клавишь?" << endl << "1.Да" << " " << "2.Нет" << endl;
			cin >> kk;
			switch (kk)
			{
			case 1:
				cout << "Включено" << endl;
			case 2:
				cout << "Отменено" << endl;
			}
		}
	}

	void km()
	{
		cout << "Дата изготовления: " << keyb << ", Фирма вашей клавиатуры: " << keybName << endl;
	}
};

class CMouse : public CDevice
{
private:
	string MouseName = "Bloody";
	int Mouse = 160000;
public:
	int mouse, ID;
	string mouseName;
	CMouse()
	{
		mouse = Mouse;
		mouseName = MouseName;
	}

	CMouse(int mouse, string mouseName)
	{
		mouse = Mouse;
		mouseName = MouseName;
	}

	void ShowDevice() override
	{
		cout << "Мышь подключена!" << endl;
	}

	void Mm()
	{
		cout << "Нажатий осталось: " << mouse << ", Фирма вашей мышки: " << mouseName << endl;
	}

	void kl()
	{
		mouse -= rand() % 10000;
		cin >> mouseName;
	}

	void uy()
	{
		int k;
		cin >> k;
		switch (k) {
		case 1:
		{
			cout << "Вы выбрали первый режим, теперь частота отклика = 1000Hz." << endl;
			mouse -= rand() % 100;
		}
		case 2:
		{
			cout << "Вы выбрали второй режим, теперь частота отклика = 500Hz." << endl;
			mouse -= rand() % 100;
		}
		case 3:
		{
			cout << "Вы выбрали третий режим, теперь частота отклика = 250Hz." << endl;
			mouse -= rand() % 50;
		}
		}
	}

	~CMouse()
	{
		mouse = 0; mouseName = " ";
	}
};

class CKeyboardMouse : public CMouse, public CKeyboard
{
public:
	void ShowDevice() override
	{
		cout << "Девайсы готовы к работе!" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	CKeyboardMouse cd; CDevice dd;
	CMouse cm; CKeyboard ck;

	cd.km();
	cout << endl;
	cd.ShowDevice();
}