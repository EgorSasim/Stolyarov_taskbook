#include <stdio.h>

void bracify();

int main(void)
{
	bracify();

	return 0;
}

void bracify()
{
	enum { IN = 1, OUT = 0 } flag = OUT;
	enum { space_char = ' ', new_line_char = '\n' };
	enum { open_brace = '(', close_brace = ')' };
	int c, prev_c;

	while ((c = getchar()) != EOF) {
		
		if (c == new_line_char) {
			if (prev_c != new_line_char && \
				prev_c != space_char && \
				prev_c != open_brace && \
				prev_c != close_brace
			   ) 
			{
				putchar(close_brace);
			}	
			goto cycle_end;
		}

		prev_c = c;

		if (c == space_char && flag == IN) {
			flag = OUT;
			putchar(close_brace);
		}

		if (c != space_char && flag == OUT) {
			flag = IN;
			putchar(open_brace);
		}	
cycle_end:
		putchar(c);
	}

}

