#include <stdio.h>
#include <stdlib.h>
#define LETTERS 41
#include <time.h>
#include <string.h>
#include <math.h>

FILE* fp;
char** text;
int i;
int j;
int k;
int ROW;


void FILL()
{
printf("enter the count of rows = ");
scanf("%d", &ROW);
printf("\n\n\n");
	for (i = 0; i < ROW; i++)
	{
		text[i] = (char*)malloc(LETTERS * sizeof(char));
	} 
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < LETTERS; j++)
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
	printf("sort stings\n\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < LETTERS; j++)
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
		printf("file is not open.\n");
		exit(1);
	}
	for (i = 0; i < ROW; ++i)
	{
		fprintf(fp, "%s\n", text[i]); 
	}
	fclose(fp);
}

void FILEREADING()
{
	if ((fp = fopen("text.txt", "r")) == NULL)
	{
		printf("file is not open.\n");
		exit(1);
	}
	for (i = 0; i < ROW; i++)
	{
		fscanf(fp, "%s", text[i]);
		fprintf(stdout, "%s\n", text[i]);
	}
	printf("\n\n\n");
}


void SORT()
{
	int flag = 0;
	for (k = 0; k < ROW - 1; k++)
	{
		for (i = 0; i < ROW - 1; i++)
		{
			
			for (j = 32; j < LETTERS - 1; j++)
			{
				if (atoi(text[i] + 32) > atoi(text[i + 1] + 32))
				{
					flag = 1;
				}
				else if (atoi(text[i] + j) > atoi(text[i + 1] + j) && (atoi(text[i] + j - 1) == atoi(text[i + 1] + j - 1)))
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
	for (i = 0; i < ROW; i++)
	{
		free(text[i]);
	}
	free(text);
}
int main(void)
{
text = (char**)malloc(ROW * sizeof(char*));
	srand(time(NULL));
	FILL();
	RECORD();
	FILEREADING();
	SORT();
    SHOW();
	CLEAR();
return 0;
}