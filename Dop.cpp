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

	while(true)
	{
		int sprob = 3, num, n, i = 1;

		cout << "Введіть число на яке ви хочете перевірити таблицю множення " << endl;
		cin >> n;
		cout << "_________________________________________________" << endl;
		do
		{

			cout << i << " * " << n << " = ";
			cin >> num;

			if (num % (n * i) != 0)
			{
				sprob--;
				cout << "___________________________" << endl;
				cout << "Залишилося " << sprob << " спроб" << endl;
				cout << "___________________________" << endl;
			}
			i++;
		} while (sprob != 0);

			cout << "You LoSer" << endl;
			cout << "___________________________" << endl;



			cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}

