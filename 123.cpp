#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main()
{
	system("chcp 1251 >nul");
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		int num,  counter = 0;

		do
		{
			cout << "Enter num" << endl;
			cin >> num;
			counter++;
		} while (num != 0);
		cout << "counter = " << counter << endl;


			cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}

