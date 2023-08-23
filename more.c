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
