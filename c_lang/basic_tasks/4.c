#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace_space_with_sign(char *buffer, char sign);
char *get_line(char *buf, int buf_size, FILE* stream);

int main(void)
{
	char *file_name = "tmp.txt"; 
	char instead_of_space_sign = '_';
	char *greeting = "Hello";
	const int buffer_size = 15;
	char *buffer = malloc(sizeof(char) * buffer_size);

	FILE *fptr = fopen(file_name, "w");
	if (!fptr) {
		printf("Unable to write to file\n");
		return 1;
	}	

	fprintf(fptr, "%3s\n", greeting);
	fprintf(fptr, "%8s\n", greeting);
	fprintf(fptr, "%-8s\n", greeting );
	fprintf(fptr, "%3.4s\n", greeting);
	fprintf(fptr, "%6.4s\n", greeting);
	fclose(fptr);

	fptr = fopen(file_name, "r");
	while (get_line(buffer, buffer_size, fptr)) {
		replace_space_with_sign(buffer, instead_of_space_sign);
		printf("buffer: %s\n", buffer);
	}	
	

	char str[] = "H e l l o , w o r l d ! ! !";
	replace_space_with_sign(str, instead_of_space_sign);
	printf("modified: %s\n", str);
	return 0;
}

char *get_line(char *buf, int buf_size, FILE* stream) 
{
	int ch, i;
	for (i = 0; i < buf_size; ++i) {
		ch = fgetc(stream);
		if (ch == '\n' || ch == EOF) {
			*(buf + i) = '\0';
			break;
		} else {
			*(buf + i) = ch;
		}
	}
	return i ? buf : NULL;
}

void replace_space_with_sign(char *buffer, char sign) 
{
	const char ascii_space_char_code = 32;
	int buffer_len = strlen(buffer);
	for (int i = 0; i < buffer_len; ++i) {
		if (*(buffer + i) == ascii_space_char_code) 
			*(buffer + i) = sign;
	}
}
