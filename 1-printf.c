#include "main.h"
/**
 * _printf - produces output according to format
 * @format: integer
 * Return: number of integers printed
 */
int _printf(const char *format, ...)
{
	int n = 0, count = 0;

	va_list nums;

	va_start(nums, format);

	while (format && format)
	{
		if (format[n] == '%')
		{
			n++;
			switch (format[n])
			{
				case 'd':
				case 'i':
					count += print_integer("%d", va_arg(nums, int));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar(format[n]);
					count += 1;
					break;
			}
		}
		else
			count += _putchar(format[n]);
		n++;
	}
	va_end(nums);
	return (count);
}
