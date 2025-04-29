#include <stdio.h>

int main(void)
{
	enum en25 { alpha = 25, beta, gamma = beta * 10, delta };
	printf("delta: %d\n", delta);
	return 0;
}
