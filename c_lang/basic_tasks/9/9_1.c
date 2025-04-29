#include <stdio.h>

void calc_words();
void calc_even_odd_words();
void calc_more_less_width_words();
void calc_A_z_words();
void calc_biggest_smallest_word();
void calc_biggest_word_and_spaces_sequence();
void calc_braces_order();
void calc_closed_braces();

int main(void)
{

	//calc_words();
	//calc_even_odd_words();
	//calc_more_less_width_words();
	//calc_A_z_words();
	//calc_biggest_smallest_word();
	calc_biggest_word_and_spaces_sequence();
	//calc_braces_order();
	//calc_closed_braces();
	return 0;
}

void calc_words()
{
	enum {IN = 1, OUT = 0} flag = OUT;
	int c, space_sign_code = 32;
	int words_cnt = 0;


	while((c = getchar()) != EOF) {
		if (c == space_sign_code && flag == IN) {
			flag = OUT;	
		}

		if (c != space_sign_code && flag == OUT) {
			flag = IN;
			++words_cnt;
		}
	}

	printf("wrods count: %d\n", words_cnt);
}

void calc_even_odd_words() 
{
	enum {IN = 1, OUT = 0} flag = OUT;
	int c, space_sign_code = 32;
	int even = 0, odd = 0, cnt = 0;


	while((c = getchar()) != EOF) {
		if (c == space_sign_code) {
			if (flag == IN) {
				if (cnt % 2) {
					++odd;
				} else {
					++even;
				}
				flag = OUT;	
				cnt = 0;
			}
		}

		if (c != space_sign_code) {
			if (flag == OUT) {
				flag = IN;
				cnt = 0;
			}
			++cnt;
		}
	}
	if (cnt != 0) {
		if (cnt % 2) {
			++odd;
		} else {
			++even;
		}

	}

	printf("even: %d\nodd: %d\n", even, odd);
	return;
}

void calc_more_less_width_words()
{
	enum {IN = 1, OUT = 0} flag = OUT;
	int c, space_sign_code = 32;
	int more_than_seven = 0, less_than_two = 0, cnt = 0;


	while((c = getchar()) != EOF) {
		if (c == space_sign_code) {
			if (flag == IN) {
				if (cnt <= 2) {
					++less_than_two;
				} 
				if (cnt > 7) {
					++more_than_seven;
				}
				flag = OUT;	
				cnt = 0;
			}
		}

		if (c != space_sign_code) {
			if (flag == OUT) {
				flag = IN;
				cnt = 0;
			}
			++cnt;
		}
	}

	if (cnt <= 2) {
		++less_than_two;
	} 
	if (cnt > 7) {
		++more_than_seven;
	}

	printf("more_than_seven: %d\nless_than_two: %d\n", more_than_seven, less_than_two);
	return;
}

void calc_A_z_words()
{
	enum {IN = 1, OUT = 0} flag = OUT;
	enum {first_char = 'A', last_char = 'z'};
	enum {space_sign_code = 32 }; 
	int c;
	char is_start_with_A = 0, last_char_in_word = 0;
	int cnt = 0;



	while((c = getchar()) != EOF) {
		if (c == space_sign_code) {
			if (flag == IN) {
				flag = OUT;
				is_start_with_A && last_char_in_word == last_char && cnt++;
				is_start_with_A = last_char_in_word = 0;

			}
		}

		if (c != space_sign_code) {
			if (flag == OUT) {
				flag = IN;
				c == first_char && (is_start_with_A = 1);
			}
			last_char_in_word = c;
		}
	}

	is_start_with_A && last_char_in_word == last_char && cnt++;

	printf("starts with \"A\" and ends with \"z\" count: %d\n", cnt);
	return;
}

void calc_biggest_smallest_word()
{
	enum {IN = 1, OUT = 0} flag = OUT;
	enum {space_sign_code = 32};
	int smallest_word_len, biggest_word_len, word_len, cnt;
	int c;
	char is_first_iteration = 1;

	smallest_word_len = biggest_word_len = word_len = cnt = 0;

	while ((c = getchar()) != EOF) {
		if (c == space_sign_code && flag == IN) {
			flag = OUT;
			biggest_word_len = word_len > biggest_word_len ? word_len : biggest_word_len;
			if (is_first_iteration) {
				smallest_word_len = word_len;
				is_first_iteration = 0;
			} else {
				smallest_word_len = word_len < smallest_word_len ? word_len : smallest_word_len;
			}
			word_len = 0;
			cnt++;
		}

		if (c != space_sign_code ) {
			if (flag == OUT) 
				flag = IN;
			word_len++;
		}
	}

	printf("biggest word len: %d\nsmallest word len: %d\ntotal words: %d\n", \
			biggest_word_len, smallest_word_len, cnt); 

	return;
}

void calc_biggest_word_and_spaces_sequence()
{
	enum {IN = 1, OUT = 0} flag = OUT;
	enum {space_sign_code = 32};
	int  biggest_word_len, biggest_space_sequence, word_len, space_len;
	int c;

	biggest_word_len = biggest_space_sequence = word_len = space_len = 0;

	while ((c = getchar()) != EOF) {
		if (c == space_sign_code) {
			if (flag == IN) {
				flag = OUT;
				biggest_word_len = word_len > biggest_word_len ? word_len : biggest_word_len;
				word_len = 0;
			}
			space_len++;
		}

		if (c != space_sign_code ) {
			if (flag == OUT) { 
				flag = IN;
				biggest_space_sequence = space_len > biggest_space_sequence \
							 ? space_len : biggest_space_sequence;
				space_len = 0;
			}
			word_len++;
		}
	}

	printf("biggest word len: %d\nbiggest space len: %d\n", biggest_word_len, biggest_space_sequence); 


	return;
}
void calc_braces_order()
{
	int open_braces_cnt = 0, close_braces_cnt = 0;
	enum {open_brace = '(', close_brace = ')'};
	int c;


	while ((c = getchar()) != EOF) {
		if (c == open_brace) {
			open_braces_cnt++;
		} 
		if (c == close_brace) {
			open_braces_cnt--;
			if (open_braces_cnt < 0) {
				printf("NO\n");
				goto end;
			}				
		}
	}

	printf(open_braces_cnt || close_braces_cnt ? "NO\n" : "YES\n"); 
end:
	return;
}

void calc_closed_braces()
{
	enum {open_brace = '(', close_brace = ')'};
	char is_open_brace_prev_symbol = 0;
	int c;
	int cnt = 0;

	while ((c = getchar()) != EOF) {
		if (c == open_brace) {
			is_open_brace_prev_symbol = 1;
		}

		if (c == close_brace && is_open_brace_prev_symbol) {
			cnt++;
			is_open_brace_prev_symbol = 0;
		}

		if (c != open_brace && c != close_brace) {
			is_open_brace_prev_symbol = 0;
		}
	}

	printf("cnt: %d\n", cnt);

	return;
}

