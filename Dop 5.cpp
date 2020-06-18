#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
//V7

void FillArr(int arr[], const int N);
void PrintArr(int arr[], const int N);
void Second(int arr[], const int N);
void Third(int arr[], const int N);
void Fourth(int arr[], const int N);
void Fift(int arr[], const int N);


//////////
int main()
{
	const int N = 20;
	int arr[N];
	srand(6);
	FillArr(arr, N);
	int n;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{

		int num;
		cout << "Menu" << endl;
		cout << "1 - ������� ���������� �����;" << endl;
		cout << "2 - ������ ������ ������� ������� ������ � ������������;" << endl;
		cout << "3 - ������ ���� ������� �� ���������� ������ ��������;" << endl;
		cout << "4 - ������ ������� ��������� ��������;" << endl;
		cout << "5 - ������� ����� ��������������� ������� ��������;" << endl;
		cout << "6 - �����." << endl;
		cout << endl << "������ ��� ����: " << endl;
		cin >> num;
		

		switch (num)
		{
		case 1:system("cls"); PrintArr(arr, N); break;										//��������� ����������� ������
		case 2:system("cls"); Second(arr, N); PrintArr(arr, N); FillArr(arr, N); break;		//���� ������ ������� �� ������������� �������� ������
		case 3:system("cls"); Third(arr, N); break;											//��������� ���� ������� �� ���������� ������ �������� ������
		case 4:system("cls"); Fourth(arr, N); break;										//��������� ������ ��������� �������� ������
		case 5:system("cls"); Fift(arr, N); break;											//��������� ������ ��������������� ������� �������� ������
		case 6:system("cls"); exit(0);
		default:cout << "Error" << endl;

		}

		system("cls");
	}
}

void FillArr(int arr[], const int N)
{

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 10 + 1;
	}

}

void PrintArr(int arr[], const int N)
{
	int n;
	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << "\t";

		}
		cout << endl << "n/N - return to menu" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) break;
		system("cls");
	}

}

void Second(int arr[], const int N)
{
	int per=0, i_per=0, max=0, i_max=0, j = 0,potoc=0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0)
		{
			j++;
			if (j == 1) { per = arr[i]; i_per = i; }
			potoc = arr[i];
			if (potoc>max)
			{
				max = arr[i];
				i_max = i;
			}
			
		}
	}
	arr[i_per] = max;
	arr[i_max] = per;
}

void Third(int arr[], const int N)
{
	int n;
	while (true)
	{
		int par2 = 0, par4 = 0, sum = 0, j = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] % 2 == 0)
			{

				if (j == 2) { par2 = arr[i]; }
				if (j == 4) { par4 = arr[i]; }
				j++;
			}

		}
		sum = par2 + par4;

		cout << endl << "C��a ������� �� ���������� ������ �������� = " << sum << endl;

		cout << "n/N - return to menu" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) break;
		system("cls");

	}

}

void Fourth(int arr[], const int N)
{
	int n;
	
	while (true)
	{
	int min=20, n_min = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == min)
		{
			n_min++;
		}
	}
	cout << "K������� ��������� ��������  - " << n_min<<endl;
	cout << "n/N - return to menu" << endl;
	n = _getch();
	if (n == 78 || n == 110 || n == 210 || n == 242) break;
	system("cls");

	}
	
}

void Fift(int arr[], const int N)
{
	int n;

	while (true)
	{
	int j= 0;
	for (int i = N; i > 0; i--)
	{
		if (arr[i] % 2 == 0)
		{
			j++;
			if (j == 2)
			{
				cout << "����� ����� ���������� ������� �������� (" << arr[i] << ") - " << i << endl; break;
			}
		}

	}
	cout << "n/N - return to menu" << endl;
	n = _getch();
	if (n == 78 || n == 110 || n == 210 || n == 242) break;
	system("cls");

}

}
