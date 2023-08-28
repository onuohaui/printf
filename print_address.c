#include "main.h"

/* Function prototypes */
int print_hex_recursive(unsigned long int n);

/**
 * print_address - Prints the memory address of a variable.
 * @args: A va_list pointing to the argument variable
 *              whose memory address will be printed.
 *
 * Return: The number of characters printed.
 */
int print_address(va_list args)
{
	unsigned long int address = va_arg(args, unsigned long int);
	int count = 0;

	if (address == 0)
	{
		return (_putstr("(nil)"));
	}

	count += _putstr("0x");
	count += print_hex_recursive(address);

	return (count);
}

/**
 * print_hex_recursive - Recursively prints a number in hexadecimal.
 * @n: The number.
 *
 * Return: The number of digits printed.
 */
int print_hex_recursive(unsigned long int n)
{
	int count = 0;
	char c;

	if (n == 0)
	{
		return (0);
	}

	count += print_hex_recursive(n / 16);

	c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + 'a');
	_putchar(c);
	count++;

	return (count);
}
