#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
//////////
void randArr(int arr[], const int N, int a, int b);
void temperatura(int arr[], const int N);
void studenti(int arr_2[], const int M);
void sportmean(int arr_3[], const int B);
void printArr(int arr[], const int N);
//////////
int main()
{
	const int N = 30;
	const int M = 20;
	const int B = 9;
	int arr[N];
	int arr_2[M];
	int arr_3[B];
	srand(6);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{

		int num;
		cout << "\t\t\t\tMenu:" << endl << endl;
		cout << "\t1 - Різниця температур між найспекотнішим та найхолоднішим днем травня." << endl;
		cout << "\t2 - Кількість груп з найменшою чисельністю студентів та номер першої з них." << endl;
		cout << "\t3 - Pезультати 10 спортсменів, які приймали участь у забігу на 10 метрів." << endl;
		cout << "\t4 - Вихід." << endl;
		cout << endl << "\tВведіть свій вибір: ";
		cin >> num;

		system("cls");system("cls");
		switch (num)
		{
		case 1:
			temperatura(arr, N);
			break;
		case 2:
			studenti(arr_2, M);
			break;
		case 3: sportmean(arr_3, M);
			break;
		case 4: exit(0);
		default:cout << "Error" << endl;
			system("pause");			break;
		}
		system("cls");
	}

}

void printArr(int arr[], const int N)
{
	cout << endl << "\t";
	for (int i = 0; i < N * 3 + 2; i++)
	{
		cout << "-";
	}
	cout << endl << "\t|";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";

	}
	cout << "|" << endl << "\t";
	for (int i = 0; i < N * 3 + 2; i++)
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

void temperatura(int arr[], const int N)
{
	randArr(arr, N, 18, 31);

	int n;
	while (true)
	{
		printArr(arr, N);
		int max = arr[0], max_index = 0;
		int min = arr[0], min_index = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i] > max)
			{
				max = arr[i];
				max_index = i;
			}
			if (arr[i] < min)
			{
				min = arr[i];
				min_index = i;
			}
		}


		cout << "\tРізниця температур між найспекотнішим(" << max_index + 1 << ") та найхолоднішим днем(" << min_index + 1 << ") травня - " << max - min << "°" << endl;
		cout << endl << "n/N - return to menu" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) break;
		system("cls");
	}
}

void studenti(int arr_2[], const int M)
{
	randArr(arr_2, M, 20, 25);
	int n;
	while (true)
	{
		int min = arr_2[0], perMin = 0, kilkist = 0, j = 0;
		printArr(arr_2, M);
		for (int i = 0; i < M; i++) {

			if (arr_2[i] < min)
			{
				min = arr_2[i];
			}
		}

		for (int i = 0; i < M; i++) {

			if (arr_2[i] == min)
			{
				if (j == 0)
				{
					perMin = i;
					j++;
				}
				kilkist++;
			}
		}

		cout << "Кількість груп з найменшою чисельністю студентів - " << kilkist << " (номер першої з них - " << perMin + 1 << ") " << endl;

		cout << endl << "n/N - return to menu" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) break;
		system("cls");
	}

}

void sportmean(int arr_3[], const int B)
{

	randArr(arr_3, B, 5, 15);
	int top1 = arr_3[0], top1_count = 0;
	int top2 = arr_3[0], top2_count = 0;


	int n;
	while (true)
	{
	for (int i = 1; i < B; i++) {
		if (arr_3[i] < top1)
		{
			top1 = arr_3[i];
		}
		if (arr_3[i] < top2 && arr_3[i] > top1)
		{
			top2 = arr_3[i];
		}
	}
	for (int i = 1; i < B; i++) {
		if (arr_3[i] == top1)
		{
			top1_count++;
		}
		if (arr_3[i] == top2)
		{
			top2_count++;
		}
	}

	int j = 0;
	int* top1Index = new int[top1_count];
	int* top2Index = new int[top2_count];


	for (int i = 1; i < B; i++)
	{
		if (arr_3[i] == top1)
		{
			top1Index[j] = i;
			j++;
		}
		if (arr_3[i] == top2)
		{
			top2Index[j] = i;
		}
	}


	if (top1_count == 1)
	{
		cout << "Перше місце займає спортсмен під номером " << top1Index[0] + 1 << " з результатом в " << arr_3[top1Index[0]] << " секунд." << endl;
	}
	else
	{
		cout << "Перше місце займають спортсмени під номером: ";
		for (int i = 0; i < top1_count; i++)
		{
			cout << top1Index[i] << " ";
		}
		cout << " з результатом в " << arr_3[top1Index[0]] << " секунд." << endl;
	}
	if (top2_count == 1)
	{
		cout << "Друге місце займає спортсмен під номером " << top2Index[0] + 1 << " з результатом в " << arr_3[top2Index[0]] << " секунд." << endl;
	}
	else
	{
		cout << "Друге місце займають спортсмени під номером: ";
		for (int i = 0; i < top2_count; i++)
		{
			cout << top2Index[i] << " ";
		}
		cout << " з результатом в " << arr_3[top2Index[0]] << " секунд." << endl;
	}

	delete[] top1Index;
	delete[] top2Index;
	cout << endl << "n/N - return to menu" << endl;
	n = _getch();
	if (n == 78 || n == 110 || n == 210 || n == 242) break;
	system("cls");
	}
}
