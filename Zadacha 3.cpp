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

		int i, n, kv = 0, max = 0, lud;
		cout << "������ ������� �������: ";
		cin >> n;

		i = 1;

		do
		{
			cout << "������ ����� ������� � ������� �" << i << ": ";
			cin >> lud;

			if (lud >= max)
			{
				max = lud;
				kv = i;
			}
			i++;
		} while (i <= n);

		cout << "__________________________________________" << endl;
		cout << "� �������i �" << kv << " ������� " << max << " ������" << endl;


		cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}

