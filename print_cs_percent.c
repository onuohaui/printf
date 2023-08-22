#include "main.h"

/**
 * print_char - print character.
 * @args: list of arguments.
 * Return: void.
 */
void print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
}

/**
 * print_string - print string.
 * @args: list of arguments.
 * Return: void.
 */
void print_string(va_list args)
{
	char *s;
	int i = 0;

	s = va_arg(args, char*);
	if (!s)
		s = "(null)";
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * print_percent - print percent symbol.
 * Return: void.
 */
void print_percent(void)
{
	_putchar('%');
}
