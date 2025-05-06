#include <stdio.h>
#include <stdlib.h>

typedef struct l_item {
	long num;
	int cnt;
	struct l_item *next;
} list_item;


list_item *read_std_in();
void print_required_digits(list_item *list, int rep_times);
char is_num_repated(list_item *list, long num);

int main(void)
{
	enum { rep_times = 3 };
	list_item *head = read_std_in();

	print_required_digits(head, rep_times);

	return 0;
}

list_item *read_std_in()
{
	list_item *head, *tmp, *current;
	long num;

	while (scanf("%ld", &num) != EOF) {
		if (!is_num_repated(head, num)) {
			tmp = malloc(sizeof(*tmp));
			tmp->num = num;
			tmp->cnt = 1;
			tmp->next = NULL;

			if (!head) {
				head = current = tmp;
			} else {
				current->next = tmp;
				current = tmp;
			}

		}
	}
	return head;	
}

char is_num_repated(list_item *list, long num)
{
	while (list) {
		if (list->num == num) {
			list->cnt++;
			return 1;
		}
		list = list->next;
	}
	return 0;
}

void print_required_digits(list_item *list, int rep_times)
{
	while (list) {
		if (list->cnt == rep_times) 
			printf("digit %5Ld occurs in stdin %3d times\n", list->num, list->cnt);
		list = list->next;
	}	
}

