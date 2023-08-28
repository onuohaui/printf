#include "main.h"

int _print_hex(unsigned int n);
int _print_hex_upper(unsigned int n);

/**
 * print_hex - Wrapper function to handle va_list and
 *	call the actual print function.
 * @args: va_list containing the unsigned int number to be printed.
 *
 * Return: The number of digits printed.
 */
int print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (_print_hex(n));
}

/**
 * _print_hex - Prints an unsigned int number in lowercase hexadecimal form.
 * @n: The unsigned int number to be printed.
 *
 * Return: The number of digits printed.
 */
int _print_hex(unsigned int n)
{
	int count = 0;
	char c;

	if (n == 0)
		return (_putchar('0'));

	if (n / 16)
		count += _print_hex(n / 16);

	c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + 'a');
	count += _putchar(c);

	return (count);
}

/**
 * print_hex_upper - Wrapper function to handle va_list and
 *	call the actual print function.
 * @args: va_list containing the unsigned int number to be printed.
 *
 * Return: The number of digits printed.
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (_print_hex_upper(n));
}

/**
 * _print_hex_upper - Prints an unsigned int
 *	number in uppercase hexadecimal form.
 * @n: The unsigned int number to be printed.
 *
 * Return: The number of digits printed.
 */
int _print_hex_upper(unsigned int n)
{
	int count = 0;
	char c;

	if (n == 0)
		return (_putchar('0'));

	if (n / 16)
		count += _print_hex_upper(n / 16);

	c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + 'A');
	count += _putchar(c);

	return (count);
}
