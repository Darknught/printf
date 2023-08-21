#include "main.h"

int _printf(const char *format, ...);

/**
 * print_string - prints a string
 * @str: string to print
 * Return: character
 */
int print_string(char *str)
{
	int i = 0;

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
	int x = 0, count = 0;
	va_list args;
	char *str;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
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
				case 'd':
				case 'i':
					count += print_number(va_arg(args, int));
					break;
				default:
					_putchar('%');
					_putchar(format[x]);
					count += 2;
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
