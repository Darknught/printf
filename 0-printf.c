#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
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
			switch (format[x])
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
					count += puts(va_arg(args, char *));
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
