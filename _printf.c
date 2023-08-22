#include "main.h"

/**
 * _printf - custom printf function
 * @format: the format string
 * ...: the list of arguments passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, len = 0;
	char *buffer;

	if (!format)
		return (-1);

	va_start(args, format);
	buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
		return (-1);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			len += handle_specifier(format[i + 1], args, buffer, len);
			i++;
		}
		else
		{
			buffer[len++] = format[i];
		}
		i++;
	}

	write(1, buffer, len);
	free(buffer);
	va_end(args);
	return (len);
}

/**
 * handle_specifier - handles format specifiers
 * @spec: the specifier character
 * @args: the va_list containing the function arguments
 * @buffer: the output buffer
 * @len: the current length of the buffer
 *
 * Return: number of characters added to the buffer
 */
int handle_specifier(char spec, va_list args, char *buffer, int len)
{
	char *str;
	char c;
	int added_len = 0;

	switch (spec)
	{
		case 'c':
			c = va_arg(args, int);
			buffer[len] = c;
			added_len = 1;
			break;
		case 's':
			str = va_arg(args, char*);
			while (*str)
			{
				buffer[len++] = *str++;
				added_len++;
			}
			break;
		case '%':
			buffer[len] = '%';
			added_len = 1;
			break;
	}
	return added_len;
}
