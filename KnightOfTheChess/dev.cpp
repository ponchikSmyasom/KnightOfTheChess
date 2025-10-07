#include "dev.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int board[8][8] = { 0 };
int moves[8][2] = { {2,1}, {1,2}, {-1,2}, {-2,1},
                   {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0;
}

int countPossibleMoves(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];
        if (isValid(newX, newY)) {
            count++;
        }
    }
    return count;
}

bool solve(int step, int x, int y) {
    board[x][y] = step;

    if (step == 64)
        return true;

    // Находим следующий ход с минимальной доступностью
    int minAccessibility = 9; // Максимум возможных ходов - 8
    int bestX = -1, bestY = -1;

    for (int i = 0; i < 8; i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];

        if (isValid(newX, newY)) {
            int accessibility = countPossibleMoves(newX, newY);

            // Выбираем ход с минимальной доступностью
            if (accessibility < minAccessibility) {
                minAccessibility = accessibility;
                bestX = newX;
                bestY = newY;
            }
        }
    }

    // Если нашли подходящий ход
    if (bestX != -1) {
        if (solve(step + 1, bestX, bestY))
            return true;
    }

    board[x][y] = 0;
    return false;
}

//печать доски
void printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

    



