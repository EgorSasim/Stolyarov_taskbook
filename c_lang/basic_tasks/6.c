#include <stdio.h>
#include <stdlib.h>

int put_sum(int *a, int *b, int *c);

int main(int argc, char **argv) 
{
	if (argc < 4) {
		printf("provide minimum 3 numbers\n");
		return 1;
	}

	int a = atoi(*(argv + 1));
	int b = atoi(*(argv + 2));
	int c = atoi(*(argv + 3));
	int sum = put_sum(&a, &b, &c);
	printf("a: %d\nb: %d\nc: %d\nsum: %d\n", a, b, c, sum);
	return 0;
}

int put_sum(int *a, int *b, int *c)
{
	int sum = *a + *b + *c;
	*a = *b = *c = sum;
	return sum;	
}
