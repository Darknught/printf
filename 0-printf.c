#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_string - prints a string
 * @str: string to print
 * Return: character
 */
int print_string(char *str)
{
	int i;

	i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int x = 0, count = 0;
	va_list args;
	char *str;

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
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					count += print_string(str);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					break;
			}
		}
		else
			count += _putchar(format[x]);
		x++;
	}
	va_end(args);
	return (count);
}
