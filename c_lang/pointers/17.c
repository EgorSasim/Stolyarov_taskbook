#include <stdio.h>
#include <stdlib.h>

typedef struct l_item {
	int data;
	struct l_item *next;	
} list_item;

list_item *make_list_form_arr(int *arr, int len);
list_item *make_list_form_arr_rec(int *arr, int len);
int *make_arr_from_list(list_item* list);
int *make_arr_from_list_rec(list_item* list);


int main(void) 
{
	enum { arr_len = 4 };
	int arr[arr_len] = { 1, 2, 3, 4 };
	int *arr2;
	list_item *list = make_list_form_arr_rec(arr, arr_len);
	list_item *list_back = list;

	int cnt = 1;
	while (list) {
		printf("list item [%d] data: %d\n", cnt++, list->data);
		list = list->next;
	}

	arr2 = make_arr_from_list_rec(list_back);

	putchar('\n');
	for (int i = 0; i < arr_len + 1; ++i) {
		printf("arr[%d]: %d\n", i + 1, *(arr2 + i));
	}

	return 0;
}

list_item *make_list_form_arr(int *arr, int len) 
{
	list_item *first = NULL, *current = NULL, *tmp = NULL;

	first = malloc(sizeof(*first));
	first->data = *arr;
	first->next = NULL;
	current = first;

	for (int i = 1; i < len; ++i) {
		tmp = (list_item *)malloc(sizeof(*tmp));
		tmp->data = *(arr + i);
		tmp->next = NULL;
		current->next = tmp;
		current = tmp;
	}
	return first;
}

list_item *make_list_form_arr_rec(int *arr, int len) 
{
	if (!len)
		return NULL;
	list_item *item = malloc(sizeof(list_item));
	item->data = *arr;
	item->next = make_list_form_arr_rec(arr + 1, len - 1);
	return item;
}

int *make_arr_from_list(list_item* list) 
{
	int list_len = 0;
	int *arr;
	int cnt = 0;
	list_item *list_back = list;

	for (; list_back; list_back = list_back->next, list_len++)
		;

	arr = malloc((list_len + 1) * sizeof(int));
	*arr = list_len;
	
	while (list) {
		*(arr + cnt + 1) = list->data; 
		list = list->next;
		cnt++;
	}

	return arr;
}

int *make_arr_from_list_rec(list_item* list) 
{
	static int *arr;
	static int arr_len = 0;

	if (!list) {
		*arr = arr_len;
		return arr;
	}

	arr_len++;
	arr = realloc(arr, arr_len + 1);
	*(arr + arr_len) = list->data;
	return make_arr_from_list_rec(list->next);
}

