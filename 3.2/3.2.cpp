#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<time.h>

int Readint()
{
	int a;
	while (!scanf("%d", &a) || a < 1)
	{
		char sym = 0;
		while (sym != '\n')
			scanf_s("%c", &sym);
		printf("wrong number\n");
	}
	return a;
}

int main()
{
	srand(time(0));
	printf("size of array = ");
	int size = Readint();
	int** arr = malloc( sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		arr[i] = malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 10;
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ( i + j == size - 1 || i == j)
			{
				printf("%3c", ' ');
				continue;
			}
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	int newsize = (size - 1) / 2;
	for (int i = 0; i < newsize; i++) //вертикальные четверти 
	{
		int p = i + 1;
		for (int j = p; j < size - p; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[size - (i + 1)][j];
			arr[size - (i + 1)][j] = temp;
		}
	}
	for (int j = 0; j < newsize; j++) //горизонтальные четверти
	{
		int p = j + 1;
		for (int i = p; i < size - p; i++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][size - j - 1];
			arr[i][size - j - 1] = temp;
		}
	}
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i + j == size - 1 || i == j)
			{
				printf("%3c", ' ');
				continue;
			}
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3i", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

