#include <stdio.h>

void print_two_char();

int main(void)
{
	print_two_char();

	return 0;
}

void print_two_char()
{
	enum { IN = 1, OUT = 0 } flag = OUT;
	enum { space_char = ' ', new_line_char = '\n' };
	int c, first_c = 0, sec_c = 0;
	int word_len = 0;

	while ((c = getchar()) != EOF) {
		
		if (c == new_line_char) {
			if (word_len == 2) {
				putchar(first_c);
				putchar(sec_c);
				putchar(' ');
			}
			first_c = sec_c = word_len = 0;
			putchar(c);
		}

		if (c == space_char && flag == IN) {
			flag = OUT;
			if (word_len == 2) {
				putchar(first_c);
				putchar(sec_c);
				putchar(' ');
			}
			first_c = sec_c = word_len = 0;
		}

		if (c != space_char) {
			flag == OUT && (flag = IN);
			word_len++;
			if (!first_c) {
				first_c = c;
			} else if (!sec_c) {
				sec_c = c;
			}	
		}	
	}

}

