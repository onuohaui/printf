#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' &&
				(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					i++;
					break;
				case 's':
					count += _print_string(va_arg(args, char *));
					i++;
					break;
				case '%':
					count += _putchar('%');
					i++;
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
 * _print_string - Prints a string.
 * @s: The string to print.
 * Return: Number of characters printed.
 */
int _print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}
