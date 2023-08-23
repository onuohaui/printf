#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Format and print data according to format string
 * @format: Character string containing format specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{

	va_list args;

	int print_count = 0;

	int i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					print_count += print_char(args);
					break;

				case 's':
					print_count += print_string(args);
					break;

				case '%':
					print_count += print_percent(args);
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			print_count++;
		}
	}

	va_end(args);

	return (print_count);
}
