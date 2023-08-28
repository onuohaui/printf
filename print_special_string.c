#include "main.h"

int print_char_as_hex(unsigned char n);

/**
 * print_special_string - Prints a string and replaces any non-printable
 *                        characters with their ASCII value in hexadecimal.
 * @args: A va_list pointing to the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_special_string(va_list args)
{
	int i;
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
	{
		return (_putstr("(null)"));
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] > 31 &&
				str[i] < 127)
		{
			_putchar(str[i]);
			count++;
		}
		else
		{
			count += _putstr("\\x");
			count += print_char_as_hex(str[i]);
		}
	}

	return (count);
}

/**
 * print_char_as_hex - Prints a number in hexadecimal form.
 * @n: The unsigned char (number) to be printed.
 *
 * Return: The number of digits printed.
 */
int print_char_as_hex(unsigned char n)
{
	int count = 0;
	char c;

	if (n < 16)
	{
		_putchar('0');
		count++;
	}

	if (n == 0)
	{
		return (_putchar('0'));
	}

	if (n / 16)
	{
		count += print_char_as_hex(n / 16);
	}

	c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + 'a');
	count += _putchar(c);

	return (count);
}
