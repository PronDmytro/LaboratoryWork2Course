#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
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
		const int N = 20;

		int arr[N];

		srand(time(NULL));

		for (int i = 0; i < N; i++)
		{
			arr[i] = rand() % 39 + 12;
		}

		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << "    ";
		}


		cout << endl << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}