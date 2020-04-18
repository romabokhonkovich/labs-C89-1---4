#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define ROW 3
#define LETTERS 100

char text[ROW][LETTERS];
int sum[10];



void FILL()
{
    printf("введите слова\n");
    for (int i = 0; i < ROW; i++)
    {
        gets_s(text[i], 100);
    }
}
 
void READ()
{
    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < strlen(text[i]); j++)
        {
            sum[i] += text[i][j];
        }
    }
}

void PRINT()
{
    for (int i = 0; i < ROW; i++)
    {
        if (sum[i] % 2 == 0)
        {
            for (int j = strlen(text[i]) - 1; j >= 0; j--)
                printf("%c", text[i][j]);
            printf("\n");
        }
        else
            printf("%s\n", text[i]);
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    FILL();//ввод
    READ();//подсчёт
    PRINT();//вывод
}
