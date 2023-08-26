#include "main.h"

/**
 * print_percent - prints the percent character.
 * @args: list of arguments passed to the function. In this case, itit is used
 *        but needed for  uniformity of function signatures.
 *
 * Return: the number of characters printed.
 */
int print_percent(va_list args __attribute__((unused)))
{
	char c = '%';

	write(1, &c, 1);

	return (1);
}

