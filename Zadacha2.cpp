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
		int el = 1,				//Перше число
			num = 0;			//Номер елемента
		double sum = 0;			//Початкова сума числ

		while (sum <= 5)												  //Поки сума числ не більше 5
		{
			cout << pow(2, (1. / el)) << " - "<< el<<"-й елемент"<< endl; //Виведення числа
			sum +=  pow(2, (1. / el));									  //Підрахунок суми числ
			el++;                                                         //Знаходження наступного числа(на 1 більше)
			num++;														  //Збільшити лічильник чисел на 1
		}
		cout << endl;
		cout << "Всього " << num << " елементів. \nЇхня сума дорівнює " << sum << endl;

			cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}
