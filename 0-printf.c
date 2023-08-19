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
	int x = 0, sum = 0;
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
					sum += _putchar(va_arg(valist, int));
					break;
				case 's':
					sum += puts(va_arg(valist, char *));
					break;
				case '%':
					sum += _putchar('%');
					break;
				default:
					break;
			}
		}
		else
			sum += _putchar(format[x]);
		x++;
	}
	va_end(valist);
	return (sum);
}
