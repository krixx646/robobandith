#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - The main function of the program
 * Description: Identify whether a number is positive or negative.
 * Return: 0 if successful, non-zero otherwise.
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d,is positive\n", n);
	}
	if (n == 0)
	{
		printf("%d, is zero\n", n);
	}
	else
	{
		printf("%d, is negative\n", n);
	}
	return (0);
}
