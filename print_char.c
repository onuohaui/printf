#include "main.h"
#include <unistd.h>

/**
 * print_char - Prints a character.
 * @args: A va_list of arguments passed to _printf.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}
