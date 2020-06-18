#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
	system("chcp 1251 >nul");
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		for (int k = 1; k <= 1; k++)
		{
			for (int i = 5; i >= 1; i--)
			{
				cout << setw(9);
				for (int j = i; j <= 5; j++)
				{
					cout << j << " ";
				}
				cout << endl;
			}

			for (int i = 1; i <= 5; i++)
			{
				for (int j = 5; j >= i; j--)
				{
					cout << j << " ";
				}
				cout << endl;
			}
		}



		cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}

