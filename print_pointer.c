#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_pointer - Prints the memory address of a pointer in hexadecimal.
 * @args: A va_list containing the pointer to be printed.
 *
 * Return: Number of characters printed.
 */

int print_pointer(va_list args)
{
	void *addr;
	char buffer[20];

	addr = va_arg(args, void *);
	sprintf(buffer, "%p", addr);

	return (write(1, buffer, strlen(buffer)));
}
