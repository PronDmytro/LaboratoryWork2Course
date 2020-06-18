#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

const int N = 5, M = 3;

void fillMatrix(int array[N][M]);
void TablMenue(string name[N], int array[N][M]);
void Vvod$(string name[N], int array[N][M]);
void zmina$(string name[N], int array[N][M]);
void VvodI(string name[N]);
void zminaI(string name[N]);
void Sum(int array[N][M]);
void tabl(string name[N], int array[N][M]);
static void loading();



int main ()
{
	//////////////////////////////////////
	//Рекомендований розміп вікна 73*14//
	/////////////////////////////////////
	system("mode con cols=73 lines=14");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");

	int ocinka[N][M];
	string name[N];

	fillMatrix(ocinka);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int n;
	while (true)
	{
		cout << "Вітаємо вас в редакторі таблиці" << endl;
		cout << "Щоб почати натисніть - 1" << endl;
		cout << "Для виходу натисніть - 0" << endl;
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			TablMenue(name, ocinka);
			system("pause");
			break;
		case 2:
			exit(0);
			break;
		default:
			cout << "Перевірте правильність введених данних." << endl;
			system("pause");
			system("cls");
		}
	}
}

void fillMatrix(int array[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			array[i][j] = 0;
		}
	}
}
void TablMenue(string name[N], int array[N][M])
{
	int n;
	while (true)
	{
		cout << "1 - Ведення ініціалів менеджерів." << endl;
		cout << "2 - Змінити ініціали." << endl;
		cout << "3 - Введення виторгу менеджерів." << endl;
		cout << "4 - Змінити виторг менеджера." << endl;
		cout << "5 - Переглянути таблицю." << endl;
		cout << "Для виходу натисніть - 0" << endl;
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			VvodI(name);
			system("pause");
			break;
		case 2:
			zminaI(name);
			system("pause");
			break;
		case 3:
			Vvod$(name,array);
			system("pause");
			break;
		case 4:
			zmina$(name,array);
			system("pause");
			break;
		case 5:
			system("color F4");
			cout << "\aЗауважте, якщо всі данні не були введені, то таблиця може відобразитися\nне коректно.\nНатисніть для продовження." << endl;
			system("pause");
			system("cls");
			system("color F0");
			tabl(name, array);
			system("pause");
			break;
		case 0:exit(0);
			break;
		default:
			cout << "Перевірте правильність введених данних." << endl;
			system("pause");
			break;
		}
		system("cls");
	}
}
void Vvod$(string name[N], int array[N][M])
{
	int n = 1;
	for (int i = 0; i < N; i++) {		// зовнішній цикл по рядках
		for (int j = 0; j < M; j++) {	// внутрішній цикл по стовпцях
			cout << "Введіть виторг працівника " << name[i] << " за " << n << "-й місяць: ";
			cin >> array[i][j];	// введення елементів з клавіатури
			n++;
		}
		n = 1;
		system("cls");
	}
}
void VvodI(string name[N])
{
	for (int i = 0; i < N; i++) 
	{
		cout << "Введіть прізвище " << i + 1 << "-го менеджера:";
		cin >> name[i];	
		system("cls");
	}
}
void zmina$(string name[N], int array[N][M])
{
	int n=1;
	int num;
	cout << "Щоб змінити виторг потрібного працівника введіть його номер : " << endl;
	cin >> num;
	if (num > 0 && num < 6)
	{
			for (int j = 0; j < M; j++) {	// внутрішній цикл по стовпцях
				cout << "Введіть виторг працівника " << name[num] << " за " << n << "-й місяць: ";
				cin >> array[num][j];	// введення елементів з клавіатури
				n++;
			}
	}
	else
	{
		cout << "Перевірте правильність введених данних." << endl;
	}
}
void zminaI(string name[N])
{
	int n;
	cout << "Щоб змінити Прізвище потрібного працівника введіть його номер : " << endl;
	cin >> n;
	if (n > 0 && n < 6)
	{
		system("cls");
		cout << "Введіть потрібне прізвище працівника під номером " << n << ": ";
		cin >> name[n];
	}
	else
	{
		cout << "Перевірте правильність введених данних." << endl;
	}
}
void Sum(int array[N][M])
{
	int sum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			sum += array[j][i];
		}
		cout << setw(9) <<  sum << "|";
		sum = 0;
	}
	cout << endl;
}
void tabl(string name[N], int array[N][M])
{
	loading();
	int sum = 0;
	cout << "| № |" << setw(10) << "Прізвище|" << setw(10) << "Січень|" << setw(10) << "Лютий|" << setw(10) << "Березень|" << setw(17) << "Усього за квартал|" << setw(10) << "Комісійні|" << endl;
	cout << "|---|---------|---------|---------|---------|-----------------|---------|" << endl;
	for (int i = 0; i < N; i++) {
		cout << "| "<< i + 1 << " |" << setw(9) << name[i];
		for (int j = 0; j < M; j++) 
		{
			cout << "|" << setw(9) << array[i][j];// << "|";
		}
		for (int k = 0; k < N; k++) 
		{
			for (int l = 0; l < M; l++) 
			{
				sum += array[k][l];
			}
			break;
		}
		cout << "|" << setw(17) << sum << "|" << setw(9) << sum * 0.02 << "|" << endl;
		cout << "|---|---------|---------|---------|---------|-----------------|---------|" << endl;
	}
	cout << "\t   Sum|";
	Sum(array);
}
static void loading() {
	cout << "\n Створення таблиці:" << endl;
	char a = 33, b = 35;
	cout << "\n\t";
	for (int i = 0; i <= 50; i++)
		cout << a;
	cout << "|\r\t|";
	for (int i = 0; i <= 50; i++) {
		cout << b;
		for (int j = 0; j <= 2e7; j++);
	}
	cout << "|\n\n Таблицю створено."<<endl; 
	system("pause");
	system("cls");
	
}