#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: A va_list pointing to the unsigned integer to be printed.
 *
 * Return: The number of digits printed.
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num, temp, count = 0, multiplier = 1;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	num = n;

	temp = num;
	while (temp > 9)
	{
		multiplier *= 10;
		temp /= 10;
	}

	while (multiplier > 0)
	{
		int digit = num / multiplier;

		_putchar(digit + '0');
		count++;
		num -= digit * multiplier;
		multiplier /= 10;
	}

	return (count);
}
