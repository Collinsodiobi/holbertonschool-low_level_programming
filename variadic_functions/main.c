#include <stdio.h>
#include "variadic_functions.h"

int main(void)
{
	printf("%d\n", sum_them_all(2, 98, 1024));
	printf("%d\n", sum_them_all(4, 98, 1024, 402, -1024));
	printf("%d\n", sum_them_all(0));
	return (0);
}
