#include <stdio.h>
#include <stdlib.h>


//!COUNTS ONLY UP TO 24 VALUE IN THE "END" ARG 

void print_sequence(int start, int end);
int  str_len(char *str);

int main(int argc, char **argv) 
{
	int start, end;
	if (argc < 3) {
		printf("Provide two numbers\n");
	}

	start = atoi(*(argv + 1));
	end   = atoi(*(argv + 2));

	print_sequence(start, end);

	return 0;
}

void print_sequence(int start, int end)
{
	int cnt 	 = 1;
	long long square = 0;
	int square_len   = 0;
	char square_buf[20];
	char *buff = NULL;
	int buf_len      = 0;

	while (str_len(buff) <= end) {
		square = (long long)cnt * cnt;
		cnt++;
		sprintf(square_buf, "%lld", square);
		square_len = str_len(square_buf);
		buf_len    = str_len(buff);
		buff       = (char *)realloc(buff, square_len * sizeof(char));
		sprintf(buff + buf_len, "%lld", square);
	}
	for (int i = 0; i <= end - start; ++i)
		putchar(*(buff + i + start - 1));
	putchar('\n');
}

int  str_len(char *str)
{
	if (!str) {
		return 0;
	}

	int i = 0;
	for (; *(str + i); ++i)
		;
	return i;
}



