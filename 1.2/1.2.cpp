#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

const int Size = 30;

void tobinary(int m, int *arr)
{
	for(int i = 0; i < Size; i++)
	{
	   arr[i] = m % 2;
	   m = m / 2;
	}

}
int Readint()
{
	int a;
	while (!scanf("%d", &a) || a < 1 || a > 10000000 )
	{
		char sym = 0;
		while (sym != '\n')
			scanf_s("%c", &sym);
		printf("ошибка ввода, повторите попытку !\n");
	}
	return a;
}
int main()
{
	setlocale(LC_ALL, "ru");
	printf("введите верхнюю границу\n");
	int m = Readint();
	int arr[Size];
	int num;
	for (int i = 1; i <= m; i++)
	{
		tobinary(i, arr);
		int flag = 1;
		for (int i = 0; i < Size; i += 3)
		{
			if (arr[i] != arr[i + 1] || arr[i] != arr[i + 2])
				flag = 0;
		}
		if (flag)
		{
			printf("\n%d\t", i);
			
			for (int i = Size-1; i >= 0; i--)
			{
				if (arr[i])
					flag = 0;
				if(!flag)
				{
					printf("%d", arr[i]);
				}
			}
		}
	}
	printf("\n");

}
