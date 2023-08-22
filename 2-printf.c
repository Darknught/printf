#include "main.h"
#include <stdarg.h>
/**
 * _printf - handle conversion specifiers
 * @format: conversion
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int x = 0, count = 0;
	va_list args;

	va_start(args, format);
	while (format && format[x])
	{
		if (format[x] == '%')
		{
			x++;
			switch (format[x - 1])
			{
				case 'u':
					count += _printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					count += _printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					count += _printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					count += _printf("%X", va_arg(args, unsigned int));
					break;
				case '%':
					count += putchar('%');
					break;
				default:
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
