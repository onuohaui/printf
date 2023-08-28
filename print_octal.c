#include "main.h"

/**
 * print_octal - Converts an unsigned integer to octal and prints it.
 * @args: A va_list pointing to the unsigned integer to be converted.
 *
 * Return: The number of digits printed.
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	count = print_octal_recursive(n);

	return (count);
}

/**
 * print_octal_recursive - Recursively converts an unsigned integer to octal.
 * @n: The unsigned integer.
 *
 * Return: The number of digits printed.
 */
int print_octal_recursive(unsigned int n)
{
	int count = 0;

	if (n == 0)
	{
		return (0);
	}

	count += print_octal_recursive(n / 8);
	_putchar((n % 8) + '0');
	count++;

	return (count);
}

