#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct l_item {
	char *str;
	struct l_item *next;
} list_item;

list_item *read_line();
void print_in_reverse_order(list_item *list);
void clear_list(list_item *list);

int main(void)
{
	list_item *list = read_line();
	print_in_reverse_order(list);
	putchar('\n');
	clear_list(list);
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

void print_in_reverse_order(list_item *list)
{
	if (!list)
		return;
	print_in_reverse_order(list->next);
	printf("%s ", list->str);
}

void clear_list(list_item *list) {
	if (!list)
		return;
	clear_list(list->next);
	free(list);
}
