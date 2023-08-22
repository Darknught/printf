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
	unsigned int ab = num < 0 ? -num : num;
	int j, count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
	}
	if (ab == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		int digits[20];
		int i = 0;

		while (ab != 0)
		{
			digits[i] = ab % 10;
			ab /= 10;
			i++;
		}
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(digits[j] + '0');
			count++;
		}
	}
	return (count);
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
