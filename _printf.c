#include "main.h"

/**
 * process_format - Processes the format and handles print to buffer
 * @format: Format string
 * @print_buf: Buffer to hold the formatted output
 * @args: Argument list for format string
 */
static void process_format(const char *format, char *print_buf, va_list args)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_to_buffer(print_buf, print_char(args));
					break;
				case 's':
					print_to_buffer(print_buf, print_string(args));
					break;
				case '%':
					print_to_buffer(print_buf, print_percent());
					break;
				case 'd':
				case 'i':
					print_to_buffer(print_buf, print_integer(args));
					break;
				case 'b':
					print_to_buffer(print_buf, print_binary(args));
					break;
					/*  Add cases for other specifiers */
				default:
					print_unknown_spec(print_buf);
					break;
			}
		}
		else
		{
			print_to_buffer(print_buf, print_char(*format));
		}

		format++;
	}
}

/**
 * _printf - Print formatted output
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	char *print_buf;
	va_list args;
	int chars_printed = 0;

	print_buf = init_print_buffer();
	if (!print_buf)
		return (-1);

	va_start(args, format);

	process_format(format, print_buf, args);

	print_buff(print_buf);
	va_end(args);

	return (chars_printed);
}

