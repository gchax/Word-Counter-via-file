#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printFile(char*, FILE*);
int countWords(char, FILE*);

int main()
{
	FILE* f1, * f2;
	char readc = {}, read[999];
	int n, count = 0;

	f1 = fopen("file.txt", "r");
	printFile(&read[0], f1);
	fclose(f1);

	f2 = fopen("file.txt", "r");
	n = countWords(readc, f2);
	printf("\n\nThere are %d words in this file.\n", n);
	fclose(f2);
	return 0;
}

void printFile(char* s, FILE* ptr)
{
	while (!feof(ptr))
	{
		fgets(s, 999, ptr);
		printf("%s", s);
	}
}

int countWords(char c, FILE* ptr)
{
	int state = 0, n = 0;
	while ((c = fgetc(ptr)) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t' || c == '\0' || c == '.' || c == ',' || c == '"' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') state = 0;
		else if (state == 0)
		{
			state = 1;
			n++;
		}
	}
	return n;
}