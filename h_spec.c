#include "main.h"

/**
 * _printf - Reproduces output according to format
 * @format - character string
 * Return: 0 (success)
 */
int _printf(const char *format, ...)
{
	int value;
	int count = 0;
	va_list a;

	va_start(a, format);

	while (*format != '\0')
	{
		if (*format == '%')
			format++;
		if (*format == '%')
			_putchar('%');
		count++;
	}
	if (*format == 'd' || *format == 'i')
	{
		value = va_arg(a, int);
		printf("%d", value);
		count++;
	}
	else
	{
		_putchar(*format);
		count++;
	}
	format++;

	va_end(a);
	return (count);
}
