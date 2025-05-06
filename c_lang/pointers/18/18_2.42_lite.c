#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
	char *str;
	int str_len;
} custom_arr;

custom_arr *read_line();
void print_in_reverse_order(custom_arr *ptr);

int main(void)
{
	custom_arr *ptr = NULL;

	while ((ptr = read_line()) != NULL) {
		print_in_reverse_order(ptr);
		putchar('\n');
	}

	return 0;
}

custom_arr *read_line()
{
	int c;
	custom_arr *arr_ptr = malloc(sizeof(*arr_ptr));
	char *str;
	int str_len = 0;

	while ((c = getchar()) != EOF) {
		str_len++;
		str = realloc(str, str_len * sizeof(char));
		*(str + str_len - 1) = c;
		if ( c == '\n' ) {
			arr_ptr->str = str;
			arr_ptr->str_len = str_len;
			return arr_ptr;
		}	

	}


	return NULL;
}

void print_in_reverse_order(custom_arr *ptr) 
{
	for (int i = ptr->str_len - 1; i >= 0; --i)
		putchar(*(ptr->str + i));
}

