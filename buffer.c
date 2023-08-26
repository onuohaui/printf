#include "main.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buf_index;

/**
 * _flush - Flushes the static buffer to stdout.
 *
 * Return: Number of characters flushed.
 */
int _flush(void)
{
	int num = 0;

	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		num = buf_index;
		buf_index = 0;
	}

	return (num);
}

/**
 * _buffer - Adds a character to the buffer. If the buffer is full, it flushes
 *           the buffer to stdout.
 * @c: The character to add.
 *
 * Return: 1 if the character is buffered or flushed, 0 otherwise.
 */
int _buffer(char c)
{
	if (buf_index >= BUFFER_SIZE - 1)
	{
		_flush();
	}

	buffer[buf_index++] = c;
	return (1);
}

/**
 * _buffer_string - Buffers a string. This uses _buffer, so it will also flush
 *                 if necessary.
 * @s: The string to buffer.
 *
 * Return: The number of characters buffered.
 */
int _buffer_string(char *s)
{
	int count = 0;

	while (*s)
	{
		_buffer(*s);
		s++;
		count++;
	}

	return (count);
}
