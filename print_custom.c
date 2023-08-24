#include "main.h"

/**
 * print_binary - Print an unsigned int as binary
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_binary(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int i, count = 0;

	for (i = 0; num > 0; i++)
	{
		if (num & 1)
			count += _putchar('1');
		else
			count += _putchar('0');

		num >>= 1;
	}

	return (count);
}

/**
 * print_reverse - Print a string in reverse
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_reverse(va_list arg)
{
	int i, count = 0;
	char *str = va_arg(arg, char*);
	int len = strlen(str);

	for (i = len - 1; i >= 0; i--)
	{
		count += _putchar(str[i]);
	}

	return (count);
}

/**
 * print_rot13 - Print a string encoded with rot13
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_rot13(va_list arg)
{
	int i, count = 0;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(arg, char*);
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = rot13[str[i] % 26];
		}
		count += _putchar(str[i]);
	}

	return (count);
}

/**
 * print_nonprint_char - Print non-printable chars as \xHH
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_nonprint_char(va_list arg)
{
	int count = 0;
	char *str = va_arg(arg, char*);
	int i = 0;

	while (str[i])
	{
		if (!is_printable(str[i]))
		{
			count += _printf("\\x%x", str[i]);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}

	return (count);
}

/**
 * print_pointer - Print a pointer address
 * @arg: Argument from _printf
 *
 * Return: Number of chars printed
 */
int print_pointer(va_list arg)
{
	void *p = va_arg(arg, void*);
	char *str = utoa_hex((unsigned long)p, "", 16);

	int count = _printf("%s", str);

	free(str);
	return (count);
}
