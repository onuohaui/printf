#include "main.h"

/* Added function prototypes */
int fetch_argument_and_print(char specifier,
		va_list args, format_t *formats);
int print_default_character(char c);

/**
 * _printf - Handle the format specifier and dispatch to appropriate functions.
 * @format: format string containing the characters and specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	format_t formats[] = {
		{"c", print_char},
		{"s", print_string},
		/* ... (other formats here) */
		{NULL, NULL}
	};
	int count = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	count = handle_format_specifier(format, args, formats);
	va_end(args);

	return (count);
}

/**
 * handle_format_specifier - Handles the parsing of the format string
 * and dispatches print operations based on format specifiers.
 * @format: format string containing the characters and specifiers
 * @args: list of arguments
 * @formats: array of format specifiers and corresponding functions
 * Return: Number of characters printed
 */
int handle_format_specifier(const char *format,
		va_list args,
		format_t *formats)
{
	unsigned int i = 0, count = 0;

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += fetch_argument_and_print(format[i + 1], args, formats);
			if (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%')
				i++;
		}
		else
		{
			count += print_default_character(format[i]);
		}
		i++;
	}
	return (count);
}

/**
 * fetch_argument_and_print - Fetch the argument corresponding to the
 * format specifier and print.
 * @specifier: format specifier character
 * @args: list of arguments
 * @formats: array of format specifiers and corresponding functions
 * Return: Number of characters printed
 */
int fetch_argument_and_print(char specifier,
		va_list args, format_t *formats)
{
	int j = 0;

	while (formats[j].fmt)
	{
		if (specifier == formats[j].fmt[0])
		{
			return (formats[j].f(args));
		}
		j++;
	}

	write(1, "%", 1);
	return (print_default_character(specifier));
}

/**
 * print_default_character - Print the character as it is.
 * @c: character to be printed
 * Return: Number of characters printed
 */
int print_default_character(char c)
{
	return (write(1, &c, 1));
}
