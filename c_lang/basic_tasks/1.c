#include <stdio.h>

int main(void) 
{
	printf("a): %d\n", '2' + 3);
	printf("b): %d\n", 3 + 'a');
	printf("c): %d\n", 'Z' - 'X');
	printf("d): %d\n", ' ' * 10);
	printf("e): %d\n", '\n' * 4);
	printf("f): %d\n", 17 / 5);
	printf("g): %d\n", 17 % 5);
	printf("h): %d\n", 17 / 15);
	printf("i): %d\n", !25);
	printf("j): %d\n", !0);
	printf("k): %d\n", 23 >> 3);
	printf("l): %d\n", 15 << 3);
	printf("m): %d\n", ~35);
	printf("n): %d\n", ~(-47));
	printf("o): %d\n", 21 ^ 15);
	printf("p): %d\n", 21 && 10);
	printf("q): %d\n", 21 & 10);
	printf("r): %d\n", 21 || 7);
	printf("s): %d\n", 21 | 7);
	printf("t): %d\n", 252 & ~15);
}
