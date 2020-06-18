#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	system("chcp 1251 >nul");
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		int i=1, num, dil=1;
		cout << "Введіть число" << endl;
		cin >> num;
		if (num > 2)
		{
			while (dil!=0)
			{
				i++;
				dil = num % i;

			}
			cout << "Найменшим дільником числа " <<num<<" є "<< i << endl;
		}
		else
		{
			cout << "Error" << endl;
		}

		cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}
