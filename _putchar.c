#include "main.h"

/**
 * flush_buffer -flush the buffer and write its content
 * Return: void
 */
void flush_buffer(void)
{
	int buffer_index, buffer;

	write(STDOUT_FILENO, buffer, buffer_index);
	buffer_index = 0;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriatetly.
 */
int _putchar(char c)
{
	char buffer[BUFF_SIZE];
	int buffer_index;

	if (buffer_index >= BUFF_SIZE)
	{
		flush_buffer();
	}
	buffer[buffer_index++] = c;
	return (1);
}
