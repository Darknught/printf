#include "main.h"

/**
 * print_integer - prints out integer
 * @num: number to print
 * Retuen: 0 (success) and length
 */
int print_integer(int num)
{
	char buffer[20];
	int i = 0;
	int j = 0;
	int length = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		length++;
	}
	while (num > 0)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
		length++;
	}
	return (length);
}
