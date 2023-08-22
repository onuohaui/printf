#include "main.h"

/**
<<<<<<< HEAD
 * _printf - Print formatted output
 * @format: Format string
 * Description: Prints formatted output based on format string.
 * Format specifiers supported:
 * %c - Print single character
 * %s - Print string
 * %% - Print literal '%' character
 * Other characters are printed as is.
 * Return: Number of characters printed
=======
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: Number of characters printed.
>>>>>>> origin/Amyb
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0;
	unsigned int i = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
<<<<<<< HEAD

	while (format[i])
	{

		if (format[i] == '%')

		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' ||
					format[i + 1] == '%' || format[i + 1] == 'd' ||
					format[i + 1] == 'i'))
=======
	while (format && format[i])
	{
		if (format[i] == '%' &&
				(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
>>>>>>> origin/Amyb
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
