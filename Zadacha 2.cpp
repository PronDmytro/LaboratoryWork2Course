#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
//V7
int main()
{
	system("chcp 1251 >nul");
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		const int N = 10;

		double arr[N];

		

		for (int i = 0; i < N; i++)
		{
			cout <<endl<< "¬вед≥ть " << i + 1 << " елемент ";
			cin >> arr[i];
		}

		for (int i = 0; i < N; i++)
		{
			arr[i] = sqrt(arr[i]);
			cout << "sqrt arr[" << i << "] = " << arr[i] << endl;
		}


		


		cout << endl << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}