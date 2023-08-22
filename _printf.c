#include "main.h"
#include <stdarg.h>
#include <stdbool.h>

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
	unsigned int count = 0;
	unsigned int i = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{

		if (format[i] == '%')

		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' ||
					format[i + 1] == '%' || format[i + 1] == 'd' ||
					format[i + 1] == 'i'))
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
				case 'd':
				case 'i':
					count += _print_int(va_arg(args, int));
					i++;
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

/**
 * _print_int - Prints an integer to stdout
 * @n: The integer
 * Return: Number of digits printed
 */
int _print_int(int n)
{
	char buffer[12]; /* Int can be up to 10 digits + sign + null terminator */
	int_to_string(n, buffer);
	return _print_string(buffer);
}

/**
 * int_to_string - Convert integer to string and store in buffer
 * @n: The integer
 * @buffer: The buffer to store the resulting string
 * Return: Pointer to the resulting string
 */
char *int_to_string(int n, char *buffer)
{
	int i = 0;
	bool isNegative = false;

	if (n == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return buffer;
	}

	if (n < 0)
	{
		isNegative = true;
		n = -n;
	}

	while (n != 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	if (isNegative)
	{
		buffer[i++] = '-';
	}

	buffer[i] = '\0';

	for (int start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
	}

	return buffer;
}
