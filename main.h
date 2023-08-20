#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

int print_string(va_list types, ...);
int print_char(va_list types, ...);
int print_per(va_list types, ...);

#endif
