#include "main.h"
#include <stdio.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * print_char - Print a character
 * @args: va_list containing the character to print
 * @count: Current character count
 * Return: Updated character count
 */
int print_char(va_list args, int count)
{
	int c = va_arg(args, int);

	putchar(c);
	count++;
	return (count);
}

/**
 * print_string - Print a string
 * @args: va_list containing the string to print
 * @count: Current character count
 * Return: Updated character count
 */
int print_string(va_list args, int count)
{
	char *s = va_arg(args, char*);

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count = print_char(args, count);
					break;
				case 's':
					count = print_string(args, count);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			buffer[buff_ind++] = *format;
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				count += buff_ind;
			}
		}
		format++;
	}

	print_buffer(buffer, &buff_ind);
	count += buff_ind;

	va_end(args);
	return (count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		for (int i = 0; i < *buff_ind; i++)
		{
			putchar(buffer[i]);
		}
	}
	*buff_ind = 0;
}
