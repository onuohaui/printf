/**
 * int_to_string - Convert an integer to its string representation.
 * @n: The integer.
 * @buffer: The buffer to save the string representation.
 *
 * Return: A pointer to the string representation.
 */
char *int_to_string(int n, char *buffer)
{
	int i = 0;
	int isNegative = 0;  /* Using int instead of bool for portability */

	/* Handle 0 explicitly */
	if (n == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return (buffer);
	}

	/* Handle negative numbers */
	if (n < 0)
	{
		isNegative = 1;
		n = -n;
	}

	/* Convert number to string */
	while (n != 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	if (isNegative)
		buffer[i++] = '-';

	buffer[i] = '\0';

	/* Reverse the string */
	for (int start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = buffer[start];

		buffer[start] = buffer[end];
		buffer[end] = temp;
	}

	return (buffer);
}
