#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct format - structure for format types
 * @type: format specifier
 * @f: function pointer
 */
typedef struct format
{
	char type;
	void (*f)(va_list);
} format_t;

/* Task 0 */
int sum_them_all(const unsigned int n, ...);

/* Task 1 */
void print_numbers(const char *separator, const unsigned int n, ...);

/* Task 2 */
void print_strings(const char *separator, const unsigned int n, ...);

/* Task 3 */
void print_all(const char * const format, ...);

#endif
