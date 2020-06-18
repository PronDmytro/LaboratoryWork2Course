#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
//////////
void randArr(int arr[], const int N, int a, int b);
void printArr(int arr[], const int N);
void del(int arr[], const int N);
void ctrlV(int arr_2[], const int M);
//////////
int main()
{

	const int N = 21;
	const int M = 11;

	int arr[N];
	int arr_2[M];

	srand(2);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{

		int num;
		cout << "\t\t\t\tMenu:" << endl << endl;
		cout << "\t1 - Видалити з масиву всі елементи, які дорівнюють максимальному." << endl;
		cout << "\t2 - Вставити в масив число 100 перед першим числом, що ділиться на 5." << endl;
		cout << "\t3 - Вихід." << endl;
		cout << endl << "\tВведіть свій вибір: ";
		cin >> num;

		system("cls"); 
		switch (num)
		{
		case 1:
			randArr(arr, N, -10, 10);
			
			del(arr, N);
			break;
		case 2:
			randArr(arr_2, M, 10, 25);
			arr_2[10] = 0;
			ctrlV(arr_2, M);
			break;
		case 3:  exit(0);
			break;
		default:cout << "Error" << endl;
			system("pause");			break;
		}
		system("cls");
	}

}

void printArr(int arr[], const int N)
{
	
	int ne_nol = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
		{
			ne_nol++;
		}
	
	}
	cout << endl <<"\t";
	for (int i = 0; i < 8* ne_nol+10; i++)
	{
		cout << "-";
	}
	cout << endl << "\t|\t";

		for (int i = 0; i < N; i++)
		{
			if (arr[i] != 0)
			{
				cout << arr[i] << "\t ";
			}
		}
	
	cout << "|" << endl << "\t";
	for (int i = 0; i < 8 * ne_nol + 10; i++)
	{
		cout << "-";
	}
	cout << endl << endl;
}

void randArr(int arr[], const int N, int a, int b)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = a + rand() % (b - a + 1);
	}
}

void del(int arr[], const int N)
{
	int n;
	while (true)
	{
		int max = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		for (int i = 1; i < N; i++)
		{
			if (arr[i] == max)
			{
				arr[i] = 0;
			}
		}
		arr[21] = 0;
		cout << "\tОперацію виконано \n\n\t1 - Вивести масив\n\t2 - Вихід в меню\n\t>>> ";
		cin >> n;
		switch (n)
		{
		case 1:printArr(arr, N); break;
		case 2:system("cls"); cout << "Точно?)" << endl;
			break;
		default:
			cout << "Error" << endl;
		}


		cout << endl << "n/N - return to menu" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) break;
		system("cls");
	}
}

void ctrlV(int arr_2[], const int M)
{
	int n;
	while (true)
	{
		cout << "\tБуло:" << endl;
		printArr(arr_2, M-1);
		int i_first5 = -1;

		for (int i = 0; i < M-1; i++)
		{
			if (arr_2[i] % 5 == 0)
			{
				i_first5 = i;
				break;
			}
		}

		if (i_first5 == -1)
		{
			cout << "Чисел які діляться на 5 немає!" << endl;
		}
		else
		{
			for (int i = M; i >= 0; i--)
			{
				if (i == i_first5)
				{
					break;
				}
				else
				{
					arr_2[i] = arr_2[i - 1];
				}
				
			}
			
		}
		arr_2[i_first5] = 100;
		cout << endl << endl << "Стало: " << endl;
		printArr(arr_2, M);
		cout << endl << "n/N - return to menu" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) break;
		system("cls");
	}
}



