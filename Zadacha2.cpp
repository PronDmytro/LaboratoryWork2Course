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
		int el = 1,				//����� �����
			num = 0;			//����� ��������
		double sum = 0;			//��������� ���� ����

		while (sum <= 5)												  //���� ���� ���� �� ����� 5
		{
			cout << pow(2, (1. / el)) << " - "<< el<<"-� �������"<< endl; //��������� �����
			sum +=  pow(2, (1. / el));									  //ϳ�������� ���� ����
			el++;                                                         //����������� ���������� �����(�� 1 �����)
			num++;														  //�������� �������� ����� �� 1
		}
		cout << endl;
		cout << "������ " << num << " ��������. \n���� ���� ������� " << sum << endl;

			cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}
