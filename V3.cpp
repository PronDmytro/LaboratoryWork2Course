#include<iostream>
#include<Windows.h>
#include<cstring>
#include <conio.h>
using namespace std;

int main()
{
	system("color F0");
	system("chcp 1251 >nul");
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
	char str[100];
	char priz[100];
	char im[100];
	char pobat[100];

	cout << "Введіть П.І.Б." << endl;
	cin.getline(str, 100);
	system("cls");
	int count = 0,j=0;
	int first, second, thirdth;
	for (int i = 0; i <= strlen(str); i++)
	{
		if (str[i] == 'е')
		{
			count++;
		}
		if (str[i] == ' ')
		{
			j++;
		}
		if (j == 0)
		{
			first = i;
		}
		if (j == 1)
		{
			second = i+1;
		}
		if (j == 2)
		{
			thirdth = i+1;
		}
	}
	strncpy_s(priz, str, first);
	strncpy_s(im, str, second);
	strncpy_s(pobat, str, thirdth);

	cout << priz<<" "<< im[0]<<"."<< pobat[0] << ". має " << count << " букв е." << endl;

	cout << "n/N - exit" << endl;
	n = _getch();
	if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
	system("cls");
	}
}

