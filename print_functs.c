#include "main.h"

/**
 * print_char - print a char
 * @arg: va_list argument
 *
 * Return: number of chars printed
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_string - print a string
 * @arg: va_list argument
 *
 * Return: number of chars printed
 */

int print_string(va_list arg)
{
	int chars = 0;
	char *str = va_arg(arg, char *);

	if (!str)
		str = "(null)";

	while (*str)
	{
		chars += _putchar(*str++);
	}

	return (chars);
}

/**
 * print_percent - print a percent symbol
 * @arg: va_list argument (unused but kept for consistency)
 *
 * Return: number of chars printed
 */

int print_percent(va_list arg)
{
	return (_putchar('%'));
}

/**
 * print_int - print an integer
 * @arg: va_list argument
 *
 * Return: number of chars printed
 */
int print_int(va_list arg)
{
	int num = va_arg(arg, int);
	char *str = itoa(num, "", 10);

	int chars = print_string(str);

	free(str);
	return (chars);
}

