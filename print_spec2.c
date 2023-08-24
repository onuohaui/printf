#include "main.h"

/**
 * print_octal - Print an unsigned int in octal
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_octal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = utoa(num, "", 8);

	int chars = print_string(str);

	free(str);
	return (chars);
}

/**
 * print_hex_lower - Print an unsigned int in lowercase hex
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_hex_lower(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = utoa(num, "", 16);

	int chars = print_string(str);

	free(str);
	return (chars);
}

/**
 * print_hex_upper - Print an unsigned int in uppercase hex
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_hex_upper(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = utoa_upper(num, "", 16);

	int chars = print_string(str);

	free(str);
	return (chars);
}

/**
 * print_binary - Print an unsigned int as binary
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_binary(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = utoa(num, "", 2);

	int chars = print_string(str);

	free(str);
	return (chars);
}
