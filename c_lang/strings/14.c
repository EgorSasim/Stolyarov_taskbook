#include <stdio.h>

void remove_spaces(char *str);
void remove_spaces2(char *str);

int main(void) 
{
	char str[] = " H  e llo   wo    rl  d   !   ";
	remove_spaces2(str);
	printf("new str: %s\n", str);

	return 0;
}

void remove_spaces(char *str)
{
	int curr_pos;
	enum { space_sign = ' ' };

	for (curr_pos = 0; *(str + curr_pos); ++curr_pos) {
		if (*(str + curr_pos) == space_sign) { 
			int i;
			for (i = curr_pos; *(str + i + 1); ++i)
			       *(str + i) = *(str + i + 1);	
			*(str + i) = '\0';
			--curr_pos;
		}
	}
}

void remove_spaces2(char *str)
{
	int shift = 0;
	int new_str_len = 0;
	enum { space_sign = ' ' };

	for (int i = 0; *(str + i); ++i) {
		if (*(str + i) == space_sign) {
			++shift;
		} else {
			++new_str_len;
			*(str + i - shift) = *(str + i);
		}
	}
	*(str + new_str_len) = '\0';
}

