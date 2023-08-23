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
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)

	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
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

			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
}
