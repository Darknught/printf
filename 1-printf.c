#include "main.h"

int print_number(int num);

/**
* print_number - prints an integer
* @num: input integer parameter
* Return: 0 (success)
*/
int print_number(int num)
{
	unsigned int ui;
	int dig, j, num_dig = 0, i = 0;
	char buffer[20];

	if (num < 0)
	{
		_putchar('-');
		ui = -num;
	}
	else
	{
		ui = num;
	}
	if (ui == 0)
	{
		_putchar('0');
		return (1);
	}
	while (ui != 0)
	{
		dig = ui % 10;
		buffer[i] = dig + '0';
		ui /= 10;
		i++;
		num_dig++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
	}
	return (num_dig);
}
/**
 * _printf - produces output according to format
 * @format: character format
 * Return: outputted character
 */
int _printf(const char *format, ...)
{
	va_list agg;
	int number = 0;
	unsigned int x;

	va_start(agg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				number++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				x = va_arg(agg, int);
				number += print_number(x);
			}
			else
			{
				_putchar('%');
				_putchar(format[x]);
				number += 2;
			}
		}
		else
		{
			_putchar(*format);
			number++;
		}
		format++;
	}
	va_end(agg);
	return (number);
}
