#include <stdio.h>

void print_words_amount(char *str);

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Provide only ONE argument!!!\n");
		return 1;
	}

	print_words_amount(*(argv + 1));
}

void print_words_amount(char *str)
{
	enum { space_char = ' ' };
	enum { IN = 1, OUT = 0 } flag = OUT;
	int word_cnt = 0;

	for (int i = 0; *(str + i); ++i)
	{
		if (*(str + i) != space_char && flag == OUT) {
			flag = IN;
			++word_cnt;
		}

		if (*(str + i) == space_char && flag == IN) {
			flag = OUT;
		}		

	}

	printf("words count: %d\n", word_cnt);
}
