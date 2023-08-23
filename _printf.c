#include "main.h"
#include <stdarg.h>

/**
 * _printf - Print formatted output
 * @format: Format string
 * Description: Prints formatted output based on format string.
 * Format specifiers supported:
 * %c - Print single character
 * %s - Print string
 * %% - Print literal '%' character
 * Other characters are printed as is.
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	unsigned int i, count;
	va_list args;

	i = 0;
	count = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _print_string(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * _print_string - Prints a string to stdout
 * @s: Pointer to the string to be printed
 * Return: number of characters printed
 */
int _print_string(char *s)
{
	int count = 0;

	while (*s)
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}
