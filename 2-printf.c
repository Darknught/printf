#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * print_unsign - outputs unsigned integers
 * @arguments: variable containing all the list
 * Return: integer
 */
int print_unsign(va_list arguments)
{
	unsigned int num = va_arg(arguments, unsigned int);
	unsigned int ab = num;
	int i = 0, digit[20], j = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (ab != 0)
	{
		digit[i] = ab % 10;
		ab /= 10;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(digit[j] + '0');
		count++;
	}
	return (count);
}

/**
 * print_octal - outputs integers in octal form
 * @arguments: variable containing all the list
 * Return: integer
 */
int print_octal(va_list arguments)
{
	unsigned int num = va_arg(arguments, unsigned int);
	int digit[20], j = 0, i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num != 0)
	{
		digit[i] = num % 8;
		num /= 8;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(digit[j] + '0');
		count++;
	}
	return (count);
}

/**
 * print_hex - outputs integer in hexadecimal
 * @arguments: list containing arguments to print hexadecimal
 * @lowercase: accepts lowercase character
 * Return: count
 */
int print_hex(va_list arguments)
{
	unsigned int num = va_arg(arguments, unsigned int);
	int i = 0, j = 0, digit[20], count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num != 0)
	{
		digit[i] = num % 16;
		num /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (digit[j] < 10)
			_putchar(digit[j] + '0');
		else
			_putchar(digit[j] - 10 + 'a');
		count++;
	}
	return (count);
}
