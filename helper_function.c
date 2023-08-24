#include "main.h"

/**
 * utoa - convert unsigned int to string
 * @num: number to convert
 * @str: pointer to output string
 * @base: base system
 *
 * Return: number of chars printed
 */
char *utoa(unsigned int num, char *str, int base)
{
	char *ptr = str;
	char *digits = "0123456789ABCDEF";

	do {
		*ptr++ = digits[num % base];
		num /= base;
	} while (num > 0);

	*ptr = '\0';
	reverse_string(str);

	return (str);
}

/**
 * itoa - convert int to string
 * @num: number to convert
 * @str: pointer to output string
 * @base: base system
 *
 * Return: number of chars printed
 */
char *itoa(int num, char *str, int base)
{
	int negative = 0;
	unsigned int n;

	if (num < 0)
	{
		negative = 1;
		n = -num;
	}
	else
	{
		n = num;
	}

	utoa(n, str, base);

	if (negative)
		*--str = '-';

	return (str);
}

/**
 * reverse_string - reverse a string
 * @str: string to reverse
 */
void reverse_string(char *str)
{
	int len = strlen(str);
	int i;
	char tmp;

	for (i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

/**
 * rot13 - encode string with rot13
 * @str: string to encode
 */
void rot13(char *str)
{
	int i;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = rot13[str[i] - 'A'];
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = rot13[str[i] - 'a' + 26];
	}
}

