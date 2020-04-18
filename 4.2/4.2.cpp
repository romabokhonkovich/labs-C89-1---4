#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LETTERS 41// количество символов в строке + '\0'
#define ROW 10//количество строк 
#include <time.h>
#include <string.h>
#include <math.h>

FILE* fp;
char** text = (char**)malloc(ROW * sizeof(char*));



void FILL()
{
	for (int i = 0; i < ROW; i++)
	{
		text[i] = (char*)malloc(LETTERS * sizeof(char));
	} 
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LETTERS; j++)
		{
			if (j < 32)
				text[i][j] = ('a' + rand() % ('z' - 'a'));
			else if (j >= 32)
				text[i][j] = ('0' + rand() % ('9' - '0'));
			text[i][LETTERS - 1] = '\0';  
		}
	}
}

void SHOW()
{
	printf("отсортированые строки\n\n");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LETTERS; j++)
		{
			printf("%c", text[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

void RECORD()
{
	if ((fp = fopen("text.txt", "w")) == NULL)
	{
		printf("невозможно открыть файл.\n");
		exit(1);
	}
	for (int i = 0; i < ROW; ++i)
	{
		fprintf(fp, "%s\n", text[i]); 
	}
	fclose(fp);
}

void FILEREADING()
{
	if ((fp = fopen("text.txt", "r")) == NULL)
	{
		printf("невозможно открыть файл.\n");
		exit(1);
	}
	for (int i = 0; i < ROW; i++)
	{
		fscanf(fp, "%s", text[i]);
		fprintf(stdout, "%s\n", text[i]);
	}
	printf("\n\n\n");
}


void SORT()//сортировка пузырьком 
{
	int flag = 0;
	for (int k = 0; k < ROW - 1; k++)
	{
		for (int i = 0; i < ROW - 1; i++)
		{
			
			for (int j = 32; j < LETTERS - 1; j++)
			{
				if (atoi(text[i] + 32) > atoi(text[i + 1] + 32))// если первая цифра первой строки больше чем первая цифра второй строки то сразу меняем местами
				{
					flag = 1;
				}
				else if (atoi(text[i] + j) > atoi(text[i + 1] + j) && (atoi(text[i] + j - 1) == atoi(text[i + 1] + j - 1)))// 
					flag = 1;
				if (flag)
				{
					char* temp;
					temp = *(text + i);
					*(text + i) = *(text + i + 1);
					*(text + i + 1) = temp;
					flag = 0;
					break;
				}
			}
		}
		
	}
}
void CLEAR()
{
	for (int i = 0; i < ROW; i++)
	{
		free(text[i]);
	}
	free(text);
}
int main(void)
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	FILL();// создание заполнение массива
	RECORD();// запись строк в файл
	FILEREADING();// чтение файла и вывод файла 
	SORT();// сортировка строк по номеру по возрастанию
    SHOW();// вывод отсортированных строк
	CLEAR();// очистка памяти
}