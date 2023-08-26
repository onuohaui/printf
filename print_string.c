#include "main.h"

/**
 * print_string - prints a string.
 * @args: list of arguments passed to the function.
 *
 * Return: the number of characters printed.
 */
int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i]; i++, count++)
	{
		write(1, &str[i], 1);
	}

	return (count);
}
