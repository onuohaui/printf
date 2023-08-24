#include "main.h"

/**
 * init_print_buffer - Initialize buffer for printing
 *
 * Return: Pointer to new buffer
 */
char *init_print_buffer(void)
{
	char *buf;

	buf = malloc(BUFF_SIZE);
	if (!buf)
	{
		return (NULL);
	}

	memset(buf, 0, BUFF_SIZE);
	return (buf);
}

/**
 * flush_print_buffer - Flush print buffer and reset index
 * @buf: Buffer to flush
 */
void flush_print_buffer(char *buf)
{
	write(1, buf, strlen(buf));
	memset(buf, 0, BUFF_SIZE);
}

/**
 * free_print_buffer - Free buffer memory
 * @buf: Buffer to free
 */
void free_print_buffer(char *buf)
{
	free(buf);
}

/**
 * print_to_buffer - Print string to buffer
 * @buf: Print buffer
 * @str: String to print
 */
void print_to_buffer(char *buf, char *str)
{
	int len = strlen(str);

	if (strlen(buf) + len >= BUFF_SIZE - 1)
	{
		flush_print_buffer(buf);
	}

	strcat(buf, str);
}

/**
 * print_buff - Print remainder of buffer
 * @buf: Print buffer
 */
void print_buff(char *buf)
{
	flush_print_buffer(buf);
	free_print_buffer(buf);
}
