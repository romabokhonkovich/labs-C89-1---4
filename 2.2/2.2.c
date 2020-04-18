#include<stdio.h>
#include<math.h>
#include<windows.h>

int main()
{
	double x, e;
	printf("x =  ");
	scanf("%lf", &x);
	printf("e = ");
	scanf("%lf", &e);
	double result = x;
	double sum = x;


	int  i = 1;
	while (e < fabs(sin(x) - sum))
	{
		result = result * (-1) * pow(x, 2) / ((2 * i) * (2 * i + 1));
	    sum += result;
	    i += 1;
		if (i > 100)
		{
			printf("uncorrect enter");
			return 0;
		}
    } 
	 

	 printf("sin(x) = %f", sin(x));
	 printf("\nsum = %f", sum);
	 printf("\nn = %d", i );
	 printf("\ne = %f", e);
	 printf("\n|sin(x) - sum| = %f",fabs(sin(x) - sum));
	 printf("\n");
         return 0;
}

