#include <iostream>
#include <Windows.h>

using namespace std;

const int N = 7, M = 3;
void fillMatrix(int array[N][M], int a, int b);
void printMatrix(int array[N][M]);
void findNegative(int array[N][M]);
int matrixSum(int array[N][M]);
void countEvenNumbers(int array[N][M]);
void maxElement(int array[N][M]);
void minElement(int array[N][M]);
void masSum(int array[N][M], int mas[N]);

int main()
{
	int mas[N][M];
	int arr[N];
	srand(8);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{

		int num;
		cout << "\t\t\t\tMenu:" << endl << endl;
		cout << "\t1 - Ініціалізація двовимірного масиву." << endl;
		cout << "\t2 - Замінити всі від’ємні елементи матриці на 0." << endl;
		cout << "\t3 - Знайти суму всіх елементів матриці." << endl;
		cout << "\t4 - Підрахувати кількість парних чисел в кожному стовпці." << endl;
		cout << "\t5 - Вивести найбільший елемент матриці та його індекси." << endl;
		cout << "\t6 - Вивести найменший елемент матриці та його індекси." << endl;
		cout << "\t7 - Утворити одновимірний масив з сум елементів кожного рядка." << endl;
		cout << "\t0 - Вихід." << endl;
		cout << endl << "\tВведіть свій вибір: ";
		cin >> num;

		system("cls");
		switch (num)
		{
		case 1:
			fillMatrix(mas, -10, 10);
			printMatrix(mas);
			system("pause");
			break;
		case 2:
			cout << "Початкова матриця: " << endl;
			printMatrix(mas);
			cout << endl << "Матриця без від'ємних елементів: " << endl;
			findNegative(mas);
			printMatrix(mas);
			fillMatrix(mas, -10, 10);
			system("pause");
			break;
		case 3:
			printMatrix(mas);
			cout << endl << endl << "Сума елементів матриці дорівнює: " << matrixSum(mas) << endl;
			system("pause");
			break;
		case 4:
			printMatrix(mas);
			countEvenNumbers(mas);
			system("pause");
			break;
		case 5:
			printMatrix(mas);
			maxElement(mas);
			system("pause");
			break;
		case 6:
			printMatrix(mas);
			minElement(mas);
			system("pause");
			break;
		case 7:
			printMatrix(mas);
			masSum(mas, arr);
			system("pause");
			break;
		case 0:
			exit(0);
			break;
		default:cout << "Error" << endl;
			system("pause");
			break;
		}
		system("cls");
	}

}

void fillMatrix(int array[N][M], int a, int b) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			array[i][j] = a + rand() % (b - a + 1);
		}
	}
}
void printMatrix(int array[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}
void findNegative(int array[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (array[i][j] < 0)
				array[i][j] = 0;
		}
	}
}
int matrixSum(int array[N][M]) {
	int Sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Sum += array[i][j];
		}
	}
	return Sum;
}
void countEvenNumbers(int array[N][M]) {
	int count = 0;
	for (int j = 0; j < M; j++) {			// зовнішній цикл по стовпцям

		for (int i = 0; i < N; i++) {		// внутрішній цикл по рядкам
			if (array[i][j] % 2 == 0)
			{
				count++;
			}
		}
		cout << "Кількість парних чисел в " << j + 1 << " cтовпці: " << count << endl;
		count = 0;							// лічильник парних елементів в стовпці
	}
}
void maxElement(int array[N][M]) {
	int max, max_i, max_j;
	max = array[0][0];					// приймемо за найбільший перший елемент масиву
	max_i = 0;							// індекси максимального елементу
	max_j = 0;
	for (int i = 0; i < N; i++) {		// зовнішній цикл по рядкам
		for (int j = 0; j < M; j++) {	// внутрішній цикл по стовпцям
			if (array[i][j] > max) {	// якщо елемент більше максимуму, то
				max = array[i][j];		// він стає найбільшим	
				max_i = i;				// запам'ятовуємо його індекси
				max_j = j;
			}
		}
	}
	cout << "   Максимальний елемент:  " << max << endl;
	cout << "   Він знаходиться у  " << max_i + 1 << " рядку та " << max_j + 1 << " стовпці" << endl;
}
void minElement(int array[N][M]) {
	int min, min_i, min_j;

	for (int i = 0; i < N; i++) {		// зовнішній цикл по рядкам
		min = array[i][0];				// приймемо за найбільший перший елемент i-го рядку
		min_i = i;						// індекси мінімального елементу
		min_j = 0;
		for (int j = 1; j < M; j++) {	// внутрішній цикл по стовпцям
			if (array[i][j] < min) {	// якщо елемент менше мінімального, то
				min = array[i][j];		// він стає мінімальним	
				min_i = i;				// запам'ятовуємо його індекси
				min_j = j;
			}
		} // виводимо мінімальний елемент рядка та його індекс:
		cout << "   Мінімальний елемент   " << i + 1 << " рядка дорівнює " << min << endl;
		cout << "   Він знаходиться у  " << min_j + 1 << " стовпці\n\n";
	}
}
void masSum(int array[N][M], int mas[N]) {
	int Sum;
	cout << "Масив з сум рядків: ";
	for (int i = 0; i < N; i++) {		// зовнішній цикл по рядкам
		Sum = 0;
		for (int j = 0; j < M; j++) {	// внутрішній цикл по стовпцям
			Sum += array[i][j];			// шукаємо суму елементів рядка
		}
		mas[i] = Sum;					// додаємо в одновимірний масив суму відповідного рядка
		cout << mas[i] << " ";
	}
	cout << endl;

}