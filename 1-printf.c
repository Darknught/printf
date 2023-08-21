#include "main.h"
/**
 * print_number - prints an integer
 * @num: input integer parameter
 * Return: 0 (success)
 */
int print_number(int num)
{
	int i = num;

	if (num < 0)
	{
		_putchar(45);
		i = -1;
	}
	if (i / 10)
	{
		print_number(i / 10);
	}
	_putchar(i % 10 + '0');
	return (0);
}

/**
 * _printf - produces output according to format
 * @format: character string
 * Return: 0 (success)
 */
int _printf(const char *format, ...)
{
	int n = 0, count = 0;
	va_list num;

	va_start(num, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format && format[n])
	{
		if (format[n] == '\0')
			return (n);
		if (format[n] == '%')
		{
			n++;
			switch (format[n])
			{
				case 'd':
				case 'i':
					count += print_number(va_arg(num, int));
					break;
				default:
					_putchar(format[n]);
					count += 1;
					break;
			}
		}
		else
		{
			_putchar(format[n]);
			count += 1;
		}
		n++;
	}
	va_end(num);
	return (count);
}
