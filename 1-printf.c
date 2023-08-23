#include "main.h"

int _printf(const char *format, ...);

/**
 * print_char - outputs a character
 * @arguments: list containing argument of character
 * Return: count
 */
int print_char(va_list arguments)
{
	char c;

	c = va_arg(arguments, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @arguments: list containing argument of string
 * Return: character
 */
int print_string(va_list arguments)
{
	char *str;
	int i;

	str = va_arg(arguments, char *);

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_number - prints an integer
 * @arguments: list containing argument of numbers
 * Return: count
 */
int print_number(va_list arguments)
{
	int num = va_arg(arguments, int);
	unsigned int ab;
	int j, digits[20], i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
	{
		_putchar('-');
		count++;
		ab = (unsigned int)(-num);
	}
	else
	{
		ab = (unsigned int)num;
	}
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
	return (count);
}

/**
 * print_binary - prints a binary number
 * @arguments: list containing argument of binary
 * Return: number to count
 */
int print_binary(va_list arguments)
{
	unsigned int num = va_arg(arguments, unsigned int);
	unsigned int tot = 1 << (sizeof(unsigned int) * 8 - 1);
	int count = 0, l_zeros = 1;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (tot != 0)
	{
		if ((num & tot) == 0)
		{
			if (!l_zeros)
			{
				_putchar('0');
				count++;
			}
		}
		else
		{
			_putchar('1');
			count++;
			l_zeros = 0;
		}
		tot >>= 1;
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
	int x, count = 0;
	va_list arguments;
	int (*myfunc)(va_list);

	va_start(arguments, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (x = 0; format && format[x]; x++)
	{
		if (format[x] == '%')
		{
			x++;
			myfunc = get_func_func(format[x]);
			if (myfunc)
			{
				count += myfunc(arguments);
			}
			else if (!myfunc && format[x] != '\0')
			{
				_putchar('%');
				_putchar(format[x]);
				count += 2;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			_putchar(format[x]);
			count++;
		}
	}
	va_end(arguments);
	return (count);
}
