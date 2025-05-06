#include <stdio.h>

int main(void)
{
	double m[] = { 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

	double *p = m + 2;

	printf("*(p + 1): %.3f\n", *(p + 1));
	printf("*(p + 3): %.3f\n", 3[p]);
	return 0;
}
