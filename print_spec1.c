#include "main.h"

/**
 * print_char - Print a character
 * @arg: va_list argument
 *
 * Return: Number of chars printed
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_string - Print a string
 * @arg: va_list argument
 *
 * Return: Number of chars printed
 */
int print_string(va_list arg)
{
	int chars = 0;
	char *str = va_arg(arg, char*);

	if (!str)
	{
		str = "(null)";
	}

	while (*str)
	{
		chars += _putchar(*str++);
	}

	return (chars);
}


/**
 * print_percent - Print a percent symbol
 * @arg: va_list argument (unused)
 *
 * Return: Number of chars printed
 */
int print_percent(va_list arg)
{
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
	char *str = itoa(num, "", 10);

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

	int chars = print_string(str);

	free(str);
	return (chars);
}
