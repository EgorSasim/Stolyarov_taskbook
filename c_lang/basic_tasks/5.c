#include <stdio.h>
#include <stdlib.h>

int get_and_zero(int *var);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Please, provide number\n");
		return 1;
	}

	int var = atoi(*(argv + 1));
	printf("func res: %d\n", get_and_zero(&var));
	printf("var: %d\n", var);
	return 0;
}

int get_and_zero(int *var)
{
	int tmp = *var;
	*var = 0;
	return tmp;
}

