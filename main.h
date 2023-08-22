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
int print_binary(unsigned int n);
int print_unsign(unsigned int num);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int lowercase);
void flush_buffer(void);

#endif
