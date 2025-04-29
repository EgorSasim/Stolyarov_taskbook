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
	int i, spaces;
	
	for(i = 0, spaces = 0; *(str + i); ++i)
		*(str + i) == ' ' && spaces++;

	return spaces;
}	
