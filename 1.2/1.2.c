#include<stdio.h>

const int Size = 30;

void tobinary(int m, int *arr)
{
    int i;
	for(i = 0; i < Size; i++)
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
			scanf("%c", &sym);
		printf("input error, try again !\n");
	}
	return a;
}
int main()
{
	printf("enter top border\n");
	int m = Readint();
	int arr[Size];
	int num;
    int i, j;
	for (i = 1; i <= m; i++)
	{
		tobinary(i, arr);
		int flag = 1;
		for (j = 0; j < Size; j += 3)
		{
			if (arr[j] != arr[j + 1] || arr[j] != arr[j + 2])
				flag = 0;
		}
		if (flag)
		{
			printf("\n%d\t", i);
			
			for (j = Size-1; j >= 0; j--)
			{
				if (arr[j])
					flag = 0;
				if(!flag)
				{
					printf("%d", arr[j]);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
