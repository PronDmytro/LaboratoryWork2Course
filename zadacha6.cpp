#include<iostream>
#include<Windows.h>
#include<cstring>
#include<conio.h>
#include<string.h>
using namespace std;


int main()
{
	system("color F0");
	system("chcp 1251 >nul");


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		int n = 0;
		char password[15];
		char symvol[23]{'.',',', ':',';','?','!','*','+','%', '-','<', '>', '@', '[',']', '{','}', '/','_', '{','}', '$' ,'#'};
		char Alf[26]{ 'A','B' ,'C' ,'D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L', 'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z' };
		char alf[26]{ 'a','b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l', 'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z' };
		char num[10]{ '1','2','3','4','5','6','7','8','9','0' };
		cout << "������ ������: ";
		cin >> password;
	
		if (strlen(password) >= 8 && strlen(password) <= 14)
		{
			if (strcspn(password, symvol) == strlen(password))
			{
				cout << "������ �� �� �������." << endl; n++;
			}
			if (strcspn(password, Alf) == strlen(password))
			{
				cout << "������ �� �� ������� ����." << endl; n++;
			}
			if (strcspn(password, alf) == strlen(password))
			{
				cout << "������ �� �� ��������� ����." << endl; n++;
			}
			if (strcspn(password, num) == strlen(password))
			{
				cout << "������ �� �� ����." << endl; n++;
			}
			if (n == 0)
			{
				cout << "������ �������� ������." << endl;
			}
		}
		else if (strlen(password) < 8)
		{
			cout << "������ ����������." << endl;
		}
		else if (strlen(password) > 12)
		{
			cout << "������ ��������." << endl;
		}

		cout << "n/N - exit" << endl;
		n = _getch();
		if (n == 78 || n == 110 || n == 210 || n == 242) exit(0);
		system("cls");
	}
}

