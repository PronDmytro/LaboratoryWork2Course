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
		int i = 0, c = 0, n;
		cout << "¬вед≥ть число" << endl;
		cin >> n;
		while (c < n) {
			c = pow(2, i);
			/*
			bool res;
			res = (c==n);
			cout << boolalpha << res << endl;*/
		
			if (c == n) {
				cout << "YES";
				break;
			}
			if (c > n) {
				cout << "NO";
			}
			i++;
		}





		cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}
