#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 3
#define LETTERS 100

char text[ROW][LETTERS];
int sum[10];
int i;
int j;


void FILL()
{
    printf("enter words: \n");
    for ( i = 0; i < ROW; i++)
    {
        gets(text[i]);
    }
}
 
void READ()
{
    
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < strlen(text[i]); j++)
        {
            sum[i] += text[i][j];
        }
    }
}

void PRINT()
{
    for (i = 0; i < ROW; i++)
    {
        if (sum[i] % 2 == 0)
        {
            for (j = strlen(text[i]) - 1; j >= 0; j--)
                printf("%c", text[i][j]);
            printf("\n");
        }
        else
            printf("%s\n", text[i]);
    }
}
int main()
{
    FILL();
    READ();
    PRINT();
    return 0;
}
