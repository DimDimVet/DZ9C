#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int volStop = 2584, volStart = 0, volStep = 1; // Task1
int sizeRows = 5, sizeCols = 5, volMax = 10;//127;  // Task2 

void Task1(int volStop, int volStart, int volStep, bool isZeroItaration); // Фибоначчи
void Task2(int volMax);
void writeConsoleArr(int (*arr)[sizeCols], int sizeRows);                    // Task2
void findCells(int input, int (*arr)[sizeCols], int sizeCols, int sizeRows); // Task2
void openCells(int x, int y);                                                // Task2

void main()
{
    printf("Run DZ9\n\n");
    Task1(volStop, volStart, volStep, true);
    Task2(volMax);
}

void Task1(int volStop, int volStart, int volStep, bool isZeroItaration)
{
    if (isZeroItaration)
    {
        printf("Task1 -> Fibonacci\t");
    }

    if (volStart > volStop)
    {
        printf("\nStop Task1\n");
        return;
    }

    printf("%d\t", volStart);
    Task1(volStop, volStep, volStart + volStep, false);
}

void Task2(int volMax)
{
    printf("\nTask2 start\n");
    int board[sizeRows][sizeCols];

    for (int i = 0; i < sizeCols; i++)
    {
        for (int j = 0; j < sizeRows; j++)
        {
            *(*(board + i) + j) = rand() % volMax;
        }
    }

    writeConsoleArr(board, sizeRows);

    int input;
    printf("In volume 0 - %d: ", volMax);
    scanf("%d", &input);

    findCells(input, board, sizeCols, sizeRows);
}

void findCells(int input, int (*arr)[sizeCols], int sizeCols, int sizeRows)
{
    for (int i = 0; i < sizeCols; i++)
    {
        for (int j = 0; j < sizeRows; j++)
        {
            if (*(*(arr + i) + j) == input)
            {
                openCells(i, j);
                *(*(arr + i) + j) = 1;
            }
            else
            {
                *(*(arr + i) + j) = 0;
            }
        }
    }
    writeConsoleArr(arr, sizeRows);
}

void writeConsoleArr(int (*arr)[sizeCols], int sizeRows)
{
    for (int i = 0; i < sizeCols; i++)
    {
        for (int j = 0; j < sizeRows; j++)
        {
            printf("|%d|", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void openCells(int x, int y)
{
    printf("Open cells (%d, %d)\n", x, y);
}
