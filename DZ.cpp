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
		cout << "\t1 - ����������� ����������� ������." << endl;
		cout << "\t2 - ������� �� �䒺�� �������� ������� �� 0." << endl;
		cout << "\t3 - ������ ���� ��� �������� �������." << endl;
		cout << "\t4 - ϳ��������� ������� ������ ����� � ������� �������." << endl;
		cout << "\t5 - ������� ��������� ������� ������� �� ���� �������." << endl;
		cout << "\t6 - ������� ��������� ������� ������� �� ���� �������." << endl;
		cout << "\t7 - �������� ����������� ����� � ��� �������� ������� �����." << endl;
		cout << "\t0 - �����." << endl;
		cout << endl << "\t������ ��� ����: ";
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
			cout << "��������� �������: " << endl;
			printMatrix(mas);
			cout << endl << "������� ��� ��'����� ��������: " << endl;
			findNegative(mas);
			printMatrix(mas);
			fillMatrix(mas, -10, 10);
			system("pause");
			break;
		case 3:
			printMatrix(mas);
			cout << endl << endl << "���� �������� ������� �������: " << matrixSum(mas) << endl;
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
	for (int j = 0; j < M; j++) {			// ������� ���� �� ��������

		for (int i = 0; i < N; i++) {		// �������� ���� �� ������
			if (array[i][j] % 2 == 0)
			{
				count++;
			}
		}
		cout << "ʳ������ ������ ����� � " << j + 1 << " c������: " << count << endl;
		count = 0;							// �������� ������ �������� � �������
	}
}
void maxElement(int array[N][M]) {
	int max, max_i, max_j;
	max = array[0][0];					// �������� �� ��������� ������ ������� ������
	max_i = 0;							// ������� ������������� ��������
	max_j = 0;
	for (int i = 0; i < N; i++) {		// ������� ���� �� ������
		for (int j = 0; j < M; j++) {	// �������� ���� �� ��������
			if (array[i][j] > max) {	// ���� ������� ����� ���������, ��
				max = array[i][j];		// �� ��� ���������	
				max_i = i;				// �����'������� ���� �������
				max_j = j;
			}
		}
	}
	cout << "   ������������ �������:  " << max << endl;
	cout << "   ³� ����������� �  " << max_i + 1 << " ����� �� " << max_j + 1 << " �������" << endl;
}
void minElement(int array[N][M]) {
	int min, min_i, min_j;

	for (int i = 0; i < N; i++) {		// ������� ���� �� ������
		min = array[i][0];				// �������� �� ��������� ������ ������� i-�� �����
		min_i = i;						// ������� ���������� ��������
		min_j = 0;
		for (int j = 1; j < M; j++) {	// �������� ���� �� ��������
			if (array[i][j] < min) {	// ���� ������� ����� ����������, ��
				min = array[i][j];		// �� ��� ���������	
				min_i = i;				// �����'������� ���� �������
				min_j = j;
			}
		} // �������� ��������� ������� ����� �� ���� ������:
		cout << "   ̳�������� �������   " << i + 1 << " ����� ������� " << min << endl;
		cout << "   ³� ����������� �  " << min_j + 1 << " �������\n\n";
	}
}
void masSum(int array[N][M], int mas[N]) {
	int Sum;
	cout << "����� � ��� �����: ";
	for (int i = 0; i < N; i++) {		// ������� ���� �� ������
		Sum = 0;
		for (int j = 0; j < M; j++) {	// �������� ���� �� ��������
			Sum += array[i][j];			// ������ ���� �������� �����
		}
		mas[i] = Sum;					// ������ � ����������� ����� ���� ���������� �����
		cout << mas[i] << " ";
	}
	cout << endl;

}