#include "main.h"
/**
 * get_func_func - function pointer that brings functions
 * @s: provided characters
 * Return: pointer to function
 */
int (*get_func_func(const char s))(va_list)
{
outfunc_t myfunc[] = {
{'c', print_char},
{'s', print_string},
{'i', print_number},
{'d', print_number},
{'b', print_binary},
{'u', print_unsign},
{'o', print_octal},
{'x', print_hex},
{'X', print_hex},
{'\0', NULL}
};

int x;

for (x = 0; myfunc[x].outfunc != '\0'; x++)
{
if (myfunc[x].outfunc == s)
return (myfunc[x].f);
}
return (NULL);
}
