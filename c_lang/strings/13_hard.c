#include <stdio.h>
#include <stdlib.h>

void print_sequence(int start, int end);
void count_digits_before_pos(int *one_char_cnt, int *two_char_cnt, int *three_char_cnt,\
	       	int *four_char_cnt, int *five_char_cnt, int *shift);
void set_buf(char *buf, int first_digit, int last_digit, int first_digit_shift, int last_digit_shift);

// square of 1    .. 3   takes 1 char   => 3   digits
// square of 4    .. 9   takes 2 chars  => 6   digits
// square of 10   .. 31  takes 3 chars  => 22  digits
// square of 32   .. 99  takes 4 chars  => 68  digits
// square of 100  .. 316 takes 5 chars  => 217 digits

enum { one_char_sq = 3, two_char_sq = 6, three_char_sq = 22,\
	four_char_sq = 68, five_char_sq = 217\
};

int main(int argc, char **argv)
{
	if (argc < 3) {
		printf("provide 'start' and 'end' of sequence\n");
		return 1;
	}

	int start = atoi(*(argv + 1));
	int end   = atoi(*(argv + 2));
	
	if (!(start && end)) {
		printf("Please, provide the correct digits\n");
		return 2;
	}

	print_sequence(start, end);

	return 0;
}

void print_sequence(int start, int end)
{
	char *buf = malloc((end - start + 1) * sizeof(char));
	int one_char_cnt = 0;
	int two_char_cnt = 0;
	int three_char_cnt = 0;
	int four_char_cnt = 0;
	int five_char_cnt = 0;
	int first_digit_shift = start;
	int last_digit_shift = end;
	int first_digit, last_digit;

	// count how many digits before 'start' position
	count_digits_before_pos(&one_char_cnt, &two_char_cnt, &three_char_cnt,\
		       	&four_char_cnt, &five_char_cnt, &first_digit_shift);
	
	// determine the actual shift of the first digit
	if (five_char_cnt) {
		first_digit_shift = 5 + first_digit_shift - 1;
	} else if (four_char_cnt) {
		first_digit_shift = 4 + first_digit_shift - 1;
	} else if (three_char_cnt) {
		first_digit_shift = 3 + first_digit_shift - 1;
	} else if (two_char_cnt) {
		first_digit_shift = 2 + first_digit_shift - 1;
	} else {
		first_digit_shift = 1 + first_digit_shift - 1;
	}	
	
	// determine first digit
	first_digit = five_char_cnt + four_char_cnt + three_char_cnt \
		      + two_char_cnt + one_char_cnt;

	one_char_cnt = 0;
        two_char_cnt = 0;
	three_char_cnt = 0; 
	four_char_cnt = 0;
	five_char_cnt = 0;
	
	//count how many digits before 'end' position
	count_digits_before_pos(&one_char_cnt, &two_char_cnt, &three_char_cnt,\
			&four_char_cnt, &five_char_cnt, &last_digit_shift);

	//determine last digit
	last_digit = five_char_cnt + four_char_cnt + three_char_cnt \
		     + two_char_cnt + one_char_cnt;
	
	set_buf(buf, first_digit, last_digit, first_digit_shift, last_digit_shift);
	printf("result sequence:\n%s\n", buf);
}

void set_buf(char *buf, int first_digit, int last_digit, int first_digit_shift, int last_digit_shift)
{
	int pos = 0;
	int first_digit_back = first_digit * first_digit;
	int first_digit_len = 0;
	char *first_digit_buf;
	while (first_digit_back) {
		first_digit_back /= 10;
		++first_digit_len;
	}

	first_digit_buf = malloc(first_digit_len * sizeof(char) + 1);
	sprintf(first_digit_buf, "%d", first_digit * first_digit);
	*(first_digit_buf + first_digit_len) = '\0';

	for (int i = first_digit_shift; *(first_digit_buf + i); ++i) {
		*(buf + pos) = *(first_digit_buf + i);
		++pos;
	}

	for (int i = first_digit + 1 ; i <= last_digit; ++i) {
		pos += sprintf(buf + pos, "%d", i * i);		
	}
	*(buf + pos + last_digit_shift) = '\0';
}

void count_digits_before_pos(int *one_char_cnt, int *two_char_cnt, int *three_char_cnt,\
		int *four_char_cnt, int *five_char_cnt, int *shift)
{

	for (int i = 0; i < one_char_sq; ++i) {
		(*one_char_cnt)++;
		*shift -= 1;
		if (*shift <= 0) 
			return;
	}

	for (int i = 0; i < two_char_sq; ++i) {
		(*two_char_cnt)++;
		*shift -= 2;
		if (*shift <= 0) 
			return;
	}

	for (int i = 0; i < three_char_sq; ++i) {
		(*three_char_cnt)++;
		*shift -= 3;
		if (*shift <= 0) 
			return;
	}

	for (int i = 0; i < four_char_sq; ++i) {
		(*four_char_cnt)++;
		*shift -= 4;
		if (*shift <= 0) 
			return;
	}

	for (int i = 0; i < five_char_sq; ++i) {
		(*five_char_cnt)++;
		*shift -= 5;
		if (*shift <= 0) 
			return;
	}
}

