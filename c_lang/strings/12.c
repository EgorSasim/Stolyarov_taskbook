#include <stdio.h>

void print_args_with_substr(char **args, int args_len, char *substr);
void print_args_with_substr_and_amount(char **args, int args_len, char *substr);
char *find_substr(char *src, char *substr);
int str_len(char *str);

int main(int argc, char **argv)
{
	if (argc < 3) {
		printf("provide at least 2 args\n");
		return 1;
	}

	print_args_with_substr_and_amount(argv + 2, argc - 2, *(argv + 1));

	return 0;
}

void print_args_with_substr(char **args, int args_len, char *substr)
{
	for (int i = 0; i < args_len; ++i) 
		if (find_substr(*(args + i), substr))
			printf("%s\n", *(args + i));	       
}

void print_args_with_substr_and_amount(char **args, int args_len, char *substr)
{
	for (int i = 0; i < args_len; ++i) { 
		int cnt = 0;
		char *ptr = *(args + i);

		while ((ptr = find_substr(ptr, substr))) {
			ptr += str_len(substr);
			cnt++;
		}
		cnt && printf("%.6s...\t| %d\n", *(args + i), cnt);	      
	}	
}

char *find_substr(char *src, char *substr)
{
	int i = 0, j = 0;
	for (i = 0; *(src + i); ++i) {
		if (str_len(src + i) < str_len(substr)) {
			return NULL;
		}

		char is_valid_substr = 1;
		for (j = 0; *(substr + j); ++j) {
			if (*(src + i + j) != *(substr + j)) {
				is_valid_substr = 0;
				break;
			}
		}

		if (is_valid_substr) 
			return src + i;

		is_valid_substr = 0;
	}

	return NULL;
}

int str_len(char *str)
{
	int i;
	for (i = 0; *(str + i); ++i)
		;
	return i;
}

