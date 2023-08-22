#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * ... : The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0, buf_index = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (buf_index == BUFFER_SIZE - 1)
		{
			write(1, buffer, buf_index);
			count += buf_index;
			buf_index = 0;
		}

		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			switch (format[i + 1])
			{
				case 'c':
					buffer[buf_index++] = (char) va_arg(args, int);
					i++;
					break;
				case 's':
					char *str = va_arg(args, char *);
					while (*str && buf_index < BUFFER_SIZE - 1)
						buffer[buf_index++] = *str++;
					i++;
					break;
				case '%':
					buffer[buf_index++] = '%';
					i++;
					break;
			}
		}
		else
		{
			buffer[buf_index++] = format[i];
		}
		i++;
	}
	va_end(args);

	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		count += buf_index;
	}

	return (count);
}
