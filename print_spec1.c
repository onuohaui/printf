#include "main.h"

/**
 * print_percent - Print a percent symbol
 * @arg: va_list argument (unused)
 *
 * Return: Number of chars printed
 */
int print_percent(va_list arg)
{
	(void)arg;
	return (_putchar('%'));
}

/**
 * print_integer - Print an integer
 * @arg: va_list argument
 *
 * Return: Number of chars printed
 */
int print_integer(va_list arg)
{
	int num = va_arg(arg, int);
	char *str = utoa(num, "");

	int chars = print_string(str);

	free(str);
	return (chars);
}

/**
 * print_unsigned - Print an unsigned integer
 * @arg: va_list argument
 *
 * Return: Number of chars printed
 */
int print_unsigned(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = utoa(num, "", 10);

	int chars = print_string(va_arg(arg, char *));

	free(str);
	return (chars);
}
