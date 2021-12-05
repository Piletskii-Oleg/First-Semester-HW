#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int summing(char str[])
{
    int sum = 0;
    int currentNumber = 0;
    for (int i = 0; i < 30; i++)
    {
        if (str[i] != -52 && isdigit(str[i]))
        {
            currentNumber = currentNumber * 10 + (str[i] - 48);
        }
        else
        {
            sum += currentNumber;
            currentNumber = 0;
            continue;
        }
    }
    return sum;
}

void count_sums(char path1[], char path2[])
{
    FILE* fptr, * gptr;
    fptr = fopen(path1, "r");
    gptr = fopen(path2, "w");

    int sum;
    int currentNumber;
    char str[30];
    while (fgets(str, 29, fptr))
    {
        printf("%d\n", summing(str));
    }

    fclose(fptr);
    fclose(gptr);
}

int main()
{
    char path1[100] = "C:\\Users\\Oleg\\source\\repos\\C Tests\\C Tests\\a.txt";
    char path2[100] = "C:\\Users\\Oleg\\source\\repos\\C Tests\\C Tests\\g.txt";
    count_sums(path1, path2);
}