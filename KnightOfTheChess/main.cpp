#include <iostream>
#include "dev.h"
using std::cout;
using std::endl;
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
 
    bool success = solve(1, 3, 3); //вернет true
    // bool success = solve(1, 0, 10); //вернет false
    // bool success = solve(1, 7, 7); //вернет true

    if (success) {
        cout << "Решение найдено!" << endl;
        printBoard();
    }
    else {
        cout << "Решение не найдено" << endl;
    }

    return 0;

	system("pause");
}