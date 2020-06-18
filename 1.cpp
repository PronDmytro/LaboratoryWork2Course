#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;


void SetColor(int text, int background)
{
    /* процедура для смены цвета шрифта */
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void printspace(int s) {
    /* для вывода пробелов (для центрироывния текста) */
    for (int i = 0; i < s; i++)
        cout << ' ';
}


void printlogo() {
    SetColor(7, 0);
    printspace(16); cout << " ##     ##    ##     ##  ######      #######  \n";
    printspace(16); cout << "  ##   ##     ##     ## ##    ##    ##     ## \n";
    printspace(16); cout << "   ## ##      ##     ## ##          ##     ## \n";
    SetColor(8, 0);
    printspace(16); cout << "    ###       ##     ##  ######     ##     ## \n";
    printspace(16); cout << "   ## ##       ##   ##        ##    ##     ## \n";
    printspace(16); cout << "  ##   ##       ## ##   ##    ##    ##     ## \n";
    printspace(16); cout << " ##     ##       ###    ######      #######  \n";
}
