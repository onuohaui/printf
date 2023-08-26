#include "main.h"

/**
 * print_rot13 - Prints a string using the ROT13 cipher
 * @args: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_rot13(va_list args)
{
	char *str;
	int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (str[i] == input[j])
			{
				_putchar(output[j]);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
