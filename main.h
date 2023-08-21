#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define NULL ((void *)0)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);

int _putchar(char c);

/* FUNCTION PROTOTYPES */
int print_string(char *str);
int print_number(int num);

#endif
