#include "main.h"

/**
 * print_binary - Converts an unsigned integer to binary and prints it.
 * @args: A va_list pointing to the unsigned integer to be converted.
 *
 * Return: The number of digits printed.
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	count = print_binary_recursive(n);

	return (count);
}

/**
 * print_binary_recursive - Recursively converts an unsigned integer to binary.
 * @n: The unsigned integer.
 *
 * Return: The number of digits printed.
 */
int print_binary_recursive(unsigned int n)
{
	int count = 0;

	if (n == 0)
	{
		return (0);
	}

	count += print_binary_recursive(n / 2);
	_putchar((n % 2) + '0');
	count++;

	return (count);
}
