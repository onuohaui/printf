#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - Writes a string to the standard output.
 * @s: The string to be written.
 *
 * Return: The number of characters written.
 */
int _putstr(char *s)
{
	int count = 0;

	while (*s)
	{
		_putchar(*s);
		count++;
		s++;
	}
	return (count);
}
