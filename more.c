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
	int i;
	char *str;

	str = va_arg(arguments, char*);

	for (i = strlen(str) - 1; i >= 0; i--)
	{
		_putchar(str[i]);
	}
	return (0);
}
