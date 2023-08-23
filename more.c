#include "main.h"

/**
 * print_percent - outputs the percentage character using putchar
 * @arguments: list of arguments in variable which wunt be used
 * Return: count
 */
int print_percent(va_list arguments)
{
	(void)arguments;
	_putchar('%');
	return (1);
}

/**
 * print_rest - outputs the character followed by the percentage
 * @arguments: list of arguments in variable
 * Return: count
 */
int print_rest(va_list arguments)
{
	char b = va_arg(arguments, int);

	_putchar('%');
	_putchar(b);
	return (2);
}

/**
 * print_custom_string - handles the %S specifier
 * @arguments: variable argument to list
 * Return: count
 */
int print_custom_string(va_list arguments)
{
	int i = 0, count = 0;
	char *str;
	unsigned int ch;

	str = va_arg(arguments, char*);

	ch = (unsigned char)str[i];

	for (i = 0; str[i] != '\0'; i++)
	{
		if (ch < 32 || ch >= 127)
		{
			count += 4;
			_putchar('\\');
			_putchar('x');
			_putchar((ch >> 4) + '0');
			_putchar((ch & 0xF) + '0');
		}
		else
		{
			_putchar(ch);
			count++;
		}
	}
	return (count);
}
