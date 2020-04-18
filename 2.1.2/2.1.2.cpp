#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<iostream>



int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int Readint()
{
	int a;
	while (!scanf("%d", &a) || a == 0)
	{
		char sym = 0;
		while (sym != '\n')
			scanf_s("%c", &sym);
		printf("wrong number\n");
	}
	return a;
}
void fun1(int *n, int *m, int *a, int *b)
{ 
	printf("введите числитель ");
	*n = Readint();
	printf("введите знаменатель ");
    *m = Readint();
	printf("введите числитель ");
	*a = Readint();
	printf("введите знаменатель ");
	*b = Readint();
}
void fun2(int n, int m, int a, int b)
{
 int t = gcd(n, m);
 int y = gcd(a, b);
    n /= t;
	m /= t;
	a /= y;
	b /= y;
	printf("%d\t", n);
	printf("%d", a);
	printf("\n—\t");
	printf("—");
	printf("\n%d", m);

	printf("\t%d\n",b);
	system("pause");
}
void fun3(int n, int m, int a, int b)
{
	int chis = (n * b + a * m);
	int znam = b * m;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("—\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun4(int n, int m, int a, int b)
{
	int chis = (n * b - a * m);
	int znam = b * m;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("—\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun5(int n, int m, int a, int b)
{
	int chis = a * n;
	int znam = b * m;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("—\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun6(int n, int m, int a, int b)
{
	int chis = n * b;
	int znam = m * a;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("—\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun7(int n, int m, int a, int b)
{
	int chis = 2 * n * a;
	int znam = m * a + b * n;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("—\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun8()
{
	printf("версия программы 1.0.0");
	printf("\nБохонкович Р.Ю.\n");
	system("\npause");
}

void menu()
{
	printf("1. Ввод (числитель и знаменатель) двух рациональных чисел.\n");
	printf("2. Вывод двух рациональных чисел (в форме: m/n).\n");
	printf("3. Сложение чисел\n");
	printf("4. Вычитание чисел\n");
	printf("5. Умножение чисел\n");
	printf("6. Деление чисел\n");
	printf("7. Получение гармонического значения\n");
	printf("8. Информация о версии и авторе программы\n");
	printf("9. Выход из программы\n");
}
int main()
{
	setlocale(LC_ALL, "ru");
	int m = 0, n = 0, a = 0, b = 0;
	int marker;
	do
	{
		system("cls");
		menu();
		while (!scanf("%d", &marker) || marker < 1 || marker > 9)
		{
			char sym = 0;
			while (sym != '\n')
				scanf_s("%c", &sym);
			printf("wrong number\n");
		}
		system("cls");
		switch (marker)
		{
		case 1: fun1(&n, &m, &a, &b); break;
		case 2: fun2(n, m, a, b); break;
		case 3: fun3(n, m, a, b); break;
		case 4: fun4(n, m, a, b); break;
		case 5: fun5(n, m, a, b); break;
		case 6: fun6(n, m, a, b); break;
		case 7: fun7(n, m, a, b); break;
		case 8: fun8(); break;
		}
	} while (marker != 9);
	
	
}

