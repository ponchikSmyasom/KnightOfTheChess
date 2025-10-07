#pragma once
#ifndef DEV_H
#define DEV_H

//подсчёт возможных ходов
int countPossibleMoves(int x, int y);

//проверка на возможность хода
bool isValid(int, int );

//решение задачи
bool solve(int, int , int);

//печать доски
void printBoard();

#endif DEV_H