#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

void randArr(int size,int *pmas);
void printArr(int size, int* pmas);
void Udal(int size);
void Dodat(int size);

int main()
{
	system("mode con cols=75 lines=14");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int size;

	while (true)
	{
		int n;
		cout << "1 - Видалити всі елементи більші середнього арифметичного елементів масиву." << endl;
		cout << "2 - Додати k випадкових елементів після першого двоцифрового числа." << endl;
		cout << "Для виходу натисніть - 0" << endl;
		cout << ">>> ";
		cin >> n;

		system("cls");
		switch (n)
		{
		case 1:
			cout << "Введіть розмір масиву: ";
			cin >> size;
			/*mas = createArray(size)
			fillMas(mas,size)
			size = func(mas,size)
			printMas(mas, size)*/

			system("cls");
			Udal(size);
			system("pause");
			break;
		case 2:
			cout << "Введіть розмір масиву: ";
			cin >> size;
			system("cls");
			Dodat(size);
			system("pause");
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Перевірте правильність введених данних." << endl;
			system("pause");
			break;
		}
		system("cls");
	}
}
void randArr(int size,int *pmas)
{
		int firstNumber, last;
		cout << "Введіть діапазон" << endl;
		cout << "Від: ";
		cin >> firstNumber;
		cout << "До: ";
		cin >> last;

		for (int i = 0; i < size; i++)
		{
			*(pmas+i) = firstNumber + rand() % (last - firstNumber + 1);
		}
}
void printArr(int size, int* pmas)
{
	cout << endl << "\n\t|";
	for (int i = 0; i < size; i++)
	{
		cout << *(pmas + i) << " ";

	}
	cout << "|\n" << endl;
}
void Udal(int size)
{
	int* pmas = new int[size];
	
	randArr(size, pmas);
	printArr(size, pmas);

	int ser=0,count=0,j=0;
	for (int i = 0; i < size; i++)
	{
		ser += *(pmas + i); 
	}
	ser /= size;
	cout <<"Ser = "<< ser << endl;
	for (int i = 0; i < size; i++)
	{
		if (*(pmas + i) > ser)
		{
			count++;
		}
	}

	int* parr = new int[count];
	
	for (int i = 0; i < size; i++)
	{
		if (*(pmas + i) < ser)
		{
			*(parr + j) = *(pmas + i);
			j++;
		}
	}
	if (j != 0)
	{
		printArr(j, parr);
	}
	else
	{
		cout << "Всі числа більші або дорівнюють середнюму арифметичному числу масиву." << endl;
	}
	delete[] pmas;
	delete[] parr;
	
}
void Dodat(int size)
{
	int* pmas = new int[size];

	randArr(size, pmas);
	printArr(size, pmas);

	int k,index=-1,j=1;
	k = rand()%11;
	for (int i = 0; i < size; i++)
	{
		if (*(pmas + i)>=10)
		{
			index = i;
			break;
		}
	}
	
	int* parr = new int[size + k];
	if (index==-1)
	{
		cout << "" << endl;
	}
	else
	{
		cout << "До масиву додано " << k << " ел., після " << index + 1 << "-го числа." << endl;
		cout << "\n\t| ";
		for (int i = 0; i < size + k; i++)
		{

			if (i <= index)
			{
				*(parr + i) = *(pmas + i);
				cout << *(parr + i) << " ";
				if (i == index)
				{
					*(parr + i + 1) = rand() % 10+1;
					cout << *(parr + i+1) << " ";
					i++;
					j++;
				}
			}
			else if (i > index && j< k)
			{
				*(parr + i) = i + rand() % 10;
				cout << *(parr + i) << " ";
				j++;
				if (j == k)
				{
					j++;
				}
			}
			else if (j==k+1)
			{
				*(parr + i) = *(pmas + i-k);
				cout << *(parr + i ) << " ";
			}
		}
		cout << "|"<<endl;
	}
	
	delete[] pmas;
	pmas = nullptr;
	delete[] parr;
	parr = nullptr;
}