#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

void randArr(int arr[], const int N, int a, int b);
void printArr(int arr[], const int N);
void zadacha_1(int arr[], const int N);
void zadacha_2(int arr[], const int M);

int main()
{
	const int N = 10;
	const int M = 20;
	int arr[N];
	int arr_2[M];
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		int num;
		cout << "\t\t\t\tMenu:" << endl << endl;
		cout << "\t1 - На скільки більше студентів навчається в найчисленнішій групі порівняно з найменшою за кількістю." << endl;
		cout << "\t2 - скільки студентів мають найнижчий бал серед студентів групи та номер у списку першого з найнижчим балом." << endl;
		cout << "\t0 - Вихід." << endl;
		cout << endl << "\tВведіть свій вибір: ";
		cin >> num;

		system("cls");
		switch (num)
		{
		case 1:
			randArr(arr, N,20,30);
			zadacha_1(arr, N);
			system("pause");
			break;
		case 2:
			randArr(arr_2, M, 2, 12);
			zadacha_2(arr_2, M);
			system("pause");
			break;
		case 0: exit(0);
		default:cout << "Error" << endl;
		}
		system("cls");
	}
}
void printArr(int arr[], const int N)
{
	
	cout << endl << "\n\t|";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";

	}
	cout << "|\n" << endl;
	
}
void randArr(int arr[], const int N, int a, int b)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = a + rand() % (b - a + 1);
	}
}
void zadacha_1(int arr[], const int N)
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
	}
	for (int i = 1; i < N; i++) {
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
	}
	cout <<"В найчисельнішій групі("<<max_index+1<<") навчається на "<<max-min<<" студентів більше в порівнянні з найменшою("<<min_index+1<<")."<< endl;
}
void zadacha_2(int arr[], const int M)
{
	printArr(arr, M);

	int min = arr[0], min_index = 0, count = 0, first = 0;
	for (int i = 1; i < M; i++) {
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
	}
	for (int i = M; i > 0; i--) {
		if (arr[i] == min)
		{
			count++;
			first = i;
		}
	}
	cout << "В групі з " << M << " чоловік найнижщий бал(" << min << ") мають " << count << " студентів. Перший з них у списку - " << first + 1  << endl;
}
