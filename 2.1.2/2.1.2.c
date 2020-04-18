#include<stdio.h>
#include<windows.h>



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
			scanf("%c", &sym);
		printf("wrong number\n");
	}
	return a;
}
void fun1(int *n, int *m, int *a, int *b)
{ 
	printf("������� ��������� ");
	*n = Readint();
	printf("������� ����������� ");
    *m = Readint();
	printf("������� ��������� ");
	*a = Readint();
	printf("������� ����������� ");
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
	printf("\n�\t");
	printf("�");
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
	printf("�\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun4(int n, int m, int a, int b)
{
	int chis = (n * b - a * m);
	int znam = b * m;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("�\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun5(int n, int m, int a, int b)
{
	int chis = a * n;
	int znam = b * m;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("�\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun6(int n, int m, int a, int b)
{
	int chis = n * b;
	int znam = m * a;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("�\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun7(int n, int m, int a, int b)
{
	int chis = 2 * n * a;
	int znam = m * a + b * n;
	int t = gcd(chis, znam);
	printf("%d\n", chis / t);
	printf("�\n");
	printf("%d\n", znam / t);
	system("pause");
}
void fun8()
{
	printf("������ ��������� 1.0.0");
	printf("\n���������� �.�.\n");
	system("\npause");
}

void menu()
{
	printf("1. ���� (��������� � �����������) ���� ������������ �����.\n");
	printf("2. ����� ���� ������������ ����� (� �����: m/n).\n");
	printf("3. �������� �����\n");
	printf("4. ��������� �����\n");
	printf("5. ��������� �����\n");
	printf("6. ������� �����\n");
	printf("7. ��������� �������������� ��������\n");
	printf("8. ���������� � ������ � ������ ���������\n");
	printf("9. ����� �� ���������\n");
}
int main()
{
	SetConsoleCP(1251); 
        SetConsoleOutputCP(1251);
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
				scanf("%c", &sym);
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
	return 0;
	
}
