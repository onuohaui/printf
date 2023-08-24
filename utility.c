#include "main.h"

/**
 * strlen - get length of string
 * @str: string
 *
 * Return: length of string
 */
int strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * strcpy - copy string
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: diff between s1 and s2
 */
int strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * puts - print string
 * @str: string to print
 */
void puts(char *str)
{
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}

