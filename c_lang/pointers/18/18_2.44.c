#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct l_item {
	char *str;
	struct l_item *next;
} list_item;

list_item *read_line();
void print_in_column(list_item *list);
void clear_list(list_item *list);
char *get_longest_digit_seq_in_string(list_item *list);
char *find__longest_digit_seq_in_word(char *word);
char is_digit(char c); 

int main(void)
{
	list_item *list;
	char *str;
	while (list = read_line()) {
		str = get_longest_digit_seq_in_string(list);
		if (str) {
			printf("longest digits seq: %s\n", str);
		} else {
			printf("no digits seq found\n");
		}
		clear_list(list);
	}
	return 0;
}

list_item *read_line()
{
	enum { IN = 1, OUT = 0 } flag = OUT;
	enum { new_line_char = '\n', space_char = ' ' };
	int c;	
	list_item *head = NULL, *current = NULL, *tmp = NULL;
	char *word = NULL;

	while ((c = getchar()) != EOF)   
	{
		if ((c == space_char || c == new_line_char) && flag == IN) {
			flag = OUT;

			tmp = malloc(sizeof(*tmp));
			tmp->str = word;
			tmp->next = NULL;

			if (!head) {
				head = current = tmp;
			} else {
				current->next = tmp;
				current = tmp;
			}

			if (c == new_line_char) 
				return head;
		}

		if (c == new_line_char)
			return head;

		if (c != space_char ) {
			if (flag == OUT) {
				flag = IN;
				word = malloc(2 * sizeof(char));
				*word = c;
				*(word + 1) = '\0';
			} else {
				int word_len = strlen(word);
				word = realloc(word, (word_len + 2) * sizeof(char));
				*(word + word_len) = c;
				*(word + word_len + 1) = '\0';
			}
		}
	}

	return NULL;
}

char *get_longest_digit_seq_in_string(list_item *list)
{
	char *longest_seq = NULL;
	char *seq = NULL;
	while (list) {
		seq = find__longest_digit_seq_in_word(list->str);
		if (seq && !longest_seq) {
			longest_seq = seq;
		} else if (seq && strlen(seq) > strlen(longest_seq)) {
			longest_seq = seq;
		}	

		list = list->next;
	}
	return longest_seq;
}

char *find__longest_digit_seq_in_word(char *word)
{
	int start_of_seq = 0, end_of_seq = 0;
	int start_of_longest_seq = 0, end_of_longest_seq = 0;
	int seq_len = 0, longest_seq_len = 0;
	char *res_seq;
	enum { IN_SEQ = 1, OUT_SEQ = 0 } flag = OUT_SEQ;

	for (int i = 0; *(word + i); ++i) {
		if (is_digit(*(word + i))) {
			if (flag == OUT_SEQ) {
				flag = IN_SEQ;
				start_of_seq = i;

			}
			seq_len++;
		}

		if (!is_digit(*(word + i)) && flag == IN_SEQ) {
			flag = OUT_SEQ;
			end_of_seq = i - 1;
			if (seq_len > longest_seq_len) {
				longest_seq_len = seq_len;
				start_of_longest_seq = start_of_seq;
				end_of_longest_seq = end_of_seq;
			}
			seq_len = 0;
		}
	}

	if (seq_len > longest_seq_len) {
		longest_seq_len = seq_len;
		start_of_longest_seq = start_of_seq;
		end_of_longest_seq = end_of_seq;
	}

	if (start_of_longest_seq && end_of_longest_seq) {
		int i;
		res_seq = malloc((end_of_longest_seq - start_of_longest_seq + 1) * sizeof(char));
		for (i = 0; i < end_of_longest_seq - start_of_seq + 1; ++i) {
			*(res_seq + i) = *(word + i + start_of_longest_seq);
		}
		*(res_seq + i) = '\0'; 
		return res_seq;
	} else {
		return NULL;
	}	
}

char is_digit(char c) {
	return c >= '0' && c <= '9';
}


void clear_list(list_item *list) {
	if (!list)
		return;
	clear_list(list->next);
	free(list);
}

