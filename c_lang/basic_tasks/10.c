#include <stdio.h>

void print_no_dash_args(int argc, char **argv);

int main(int argc, char **argv) 
{
	print_no_dash_args(argc, argv);
	return 0;
}

void print_no_dash_args(int argc, char **argv)
{
	for (int i = 1; i < argc; **(argv + i) != '-' && printf("%s\n", *(argv + i)), ++i) 
		;
}

