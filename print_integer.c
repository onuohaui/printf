#include "main.h"

/**
 * print_integer - Prints an integer.
 * @args: A va_list pointing to the integer to be printed.
 *
 * Return: The number of digits printed.
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int num, temp, count = 0, multiplier = 1;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

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
