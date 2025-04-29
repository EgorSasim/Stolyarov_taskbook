#include <stdio.h>

void print_longest_arg_and_length(char **args, int args_len);
void print_non_repeated_letters_words(char **args, int args_len);
void print_word_with_dog_and_dot(char **argv, int args_len);
void print_only_digit_words(char **args, int args_len);
void print_one_symbol_words(char **args, int args_len);
void print_latin_letter_words(char **args, int args_len);
void print_words_with_same_letters(char **args, int args_len);
int  is_words_with_same_letters(char *word1, char *word2);
int  is_word_contains_latin_letter(char *word);
int  is_one_symbol_word(char *word);
int  is_digit_string(char *str);
int  is_word_contains_dog_and_dot(char *word);
int  is_words_with_no_repeated_letters(char *word);
int  str_len(char *str);

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Please provide at least one arg\n");
		return 1;
	}

	//print_longest_arg_and_length(argv + 1, argc - 1);
	//print_non_repeated_letters_words(argv + 1, argc -1);
	//print_word_with_dog_and_dot(argv + 1, argc - 1);
	//print_only_digit_words(argv + 1, argc - 1);
	//print_one_symbol_words(argv + 1, argc - 1);
	//print_latin_letter_words(argv + 1, argc - 1);
	print_words_with_same_letters(argv + 1, argc - 1);
	return 0;
}

void print_longest_arg_and_length(char **args, int args_len)
{
	char *longest_arg = NULL;
	int longest_len = 0, len = 0;

	for (int i = 0; i < args_len; ++i) {
		for (int j = 0; *(*(args + i) + j); ++j, ++len)
			;
		if (len > longest_len) {
			longest_arg = *(args + i);
			longest_len = len;
		}
		len = 0;
	}
	printf("Longest arg: %s\nwith length: %d\n", longest_arg, longest_len);
}

void print_non_repeated_letters_words(char **args, int args_len)
{
	for (int i = 0; i < args_len; ++i)
		is_words_with_no_repeated_letters(*(args + i)) && \
			printf("%s\n", *(args + i));

}

void print_word_with_dog_and_dot(char **argv, int args_len)
{
	for (int i = 0; i < args_len; ++i)
		is_word_contains_dog_and_dot(*(argv + i)) && \
			printf("%s\n", *(argv + i));	
}

void print_only_digit_words(char **args, int args_len)
{
	for (int i = 0; i < args_len; ++i)
		is_digit_string(*(args + i)) && \
			printf("%s\n", *(args + i));
}

void print_one_symbol_words(char **args, int args_len)
{
	for (int i = 0; i < args_len; ++i)
		is_one_symbol_word(*(args + i)) && \
			printf("%s\n", *(args + i));
}

void print_latin_letter_words(char **args, int args_len)
{
	for (int i = 0; i < args_len; ++i)
		is_word_contains_latin_letter(*(args + i)) && \
			printf("%s\n", *(args + i));
}

void print_words_with_same_letters(char **args, int args_len)
{
	for (int i = 1; i < args_len; ++i)
		is_words_with_same_letters(*args, *(args + i)) && \
			printf("%s\n", *(args + i));
}

int  is_words_with_same_letters(char *word1, char *word2)
{
	for (int i = 0; *(word1 + i); ++i)
		for (int j = 0; *(word2 + j); ++j)
			if (*(word1 + i) == *(word2 + j))
				return 1;
	return 0;
}

int  is_word_contains_latin_letter(char *word)
{
	for (int i = 0; *(word + i); ++i)
		if ((*(word + i) >= 'a' && *(word + i) <= 'z') || \
				(*(word + i) >= 'A' && *(word + i) <= 'Z')) 
			return 1;
	return 0;
}

int  is_one_symbol_word(char *word)
{
	for (int i = 0; *(word + i); ++i)
		if (*word != *(word + i))
			return 0;
	return 1;
}

int  is_digit_string(char *str)
{
	for (int i = 0; *(str + i); ++i)
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
			return 0;
	return 1;
}

int  is_word_contains_dog_and_dot(char *word)
{
	enum { dog_sign = '@', dot_sign = '.' };
	char is_dog_sign_here = 0, is_dot_sign_here = 0;

	for (int i = 0; *(word + i); ++i) {
		if (*(word + i) == dog_sign) {
			++is_dog_sign_here;
		}
		if (*(word + i) == dot_sign) {
			++is_dot_sign_here;
		}
	}
	return (is_dog_sign_here == 1) && is_dot_sign_here;
}

int  is_words_with_no_repeated_letters(char *word)
{
	int word_len = str_len(word);
	for (int i = 0; i < word_len - 1; ++i) 
		for (int j = i + 1; j < word_len; ++j)
			if (*(word + i) == *(word + j))
				return 0;
	return 1;
}

int  str_len(char *str)
{
	int i;
	for (i = 0; *(str + i); ++i)
		;
	return i;
}
