#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * print_unsign - outputs unsigned integers
 * @num: int to output
 * Return: integer
 */
int print_unsign(unsigned int num)
{
	unsigned int ab = num;
	int i, digit[20], j = 0, count = 0;

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
 * @num: integer to print
 * Return: integer
 */
int print_octal(unsigned int num)
{
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
 * @num: integer to print
 * @lowercase: accepts lowercase character
 * Return: integer
 */
int print_hex(unsigned int num, int lowercase)
{
	int i = 0, j = 0, digit[20], count = 0;
	char hex_base = lowercase ? 'a' : 'A';

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
			_putchar(digit[j] - 10 + hex_base);
		count++;
	}
	return (count);
}

/**
 * _printf - handle conversion specifiers
 * @format: conversion
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int x = 0, count = 0;
	unsigned int num;
	va_list args;

	va_start(args, format);
	while (format && format[x])
	{
		if (format[x] == '\0')
			return (x);
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
				case 'u':
					num = va_arg(args, unsigned int);
					count += print_unsign(num);
					break;
				case 'o':
					num = va_arg(args, unsigned int);
					count += print_octal(num);
					break;
				case 'x':
					num = va_arg(args, unsigned int);
					count += print_hex(num, 1);
					break;
				case 'X':
					num = va_arg(args, unsigned int);
					count += print_hex(num, 0);
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(format[x]);
					count += 2;
					break;
			}
		}
		else
			count += putchar(format[x]);
		x++;
	}
	va_end(args);
	return (count);
}
