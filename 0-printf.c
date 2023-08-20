#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int print_string(va_list types, ...);
int print_char(va_list types, ...);
int print_per(va_list types, ...);
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int x = 0, count = 0;
	va_list valist;

	va_start(valist, format);
	while (format && format[x])
	{
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
				case 'c':
					count += putchar(va_arg(valist, int));
					break;
				case 's':
					count += puts(va_arg(valist, char *));
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
	va_end(valist);
	return (count);
}
