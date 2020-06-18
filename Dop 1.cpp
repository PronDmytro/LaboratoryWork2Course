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
		int cina, kil, sum1 = 0,n=0;
		double	sum = 0;
		do {
			cout << "Введіть ціну товару: ";
			cin >> cina;
			cout << "Введіть кількість товару: ";
			cin >> kil;
			cout << "__________________________" << endl;
			if (kil >= 10)
			{
				sum1 = (cina * kil);
				sum = sum1-sum1*0.05;
			}
			else
			{
				sum1 = (cina * kil);
				sum += sum1;

			}
			n++;
		} while (cina != 0 && kil != 0);

		if (sum > 2000)
		{
			sum = sum - sum * 0.03;
		}
		n--;
		cout << "Кількість товарів " <<n<< endl;
		cout <<"До сплати " <<sum<<" grn"<<endl;

			cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}

