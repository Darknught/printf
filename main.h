#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define NULL ((void *)0)

int _printf(const char *format, ...);

int _putchar(char c);

/* FUNCTION PROTOTYPES */
int print_string(char *str);

#endif
