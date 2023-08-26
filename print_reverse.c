#include "main.h"

/**
 * print_reverse - Prints a string in reverse
 * @args: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_reverse(va_list args)
{
	char *str;
	int len = 0, i;
	int count = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}

	return (count);
}
