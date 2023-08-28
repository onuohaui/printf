#include "main.h"

/**
 * print_percent - prints the percent character.
 * @args: list of arguments passed to the function. In this case, itit is used
 *        but needed for  uniformity of function signatures.
 *
 * Return: the number of characters printed.
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');

	return (1);
}
