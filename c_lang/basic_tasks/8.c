#include <stdio.h>

int calc_spaces(char *str);

int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	printf("spaces: %d\n", calc_spaces(*(argv + 1)));

	return 0;
}

int calc_spaces(char *str)
{
	if (!*(str))
		return 0;
	if (*str == ' ') 
		return calc_spaces(str + 1) + 1;
	else 
		return calc_spaces(str + 1);
}
