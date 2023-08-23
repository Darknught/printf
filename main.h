#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * struct outfunc - struct pointer
 * @outfunc: the pointer
 * @f: function pointer
 */
typedef struct outfunc
{
	char outfunc;
	int (*f)(va_list);
} outfunc_t;


#define NULL ((void *)0)
#define BUFF_SIZE 1024
#define PI 3.14159
#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);

int _putchar(char c);

/* FUNCTION PROTOTYPES */
int print_char(va_list arguments);
int print_string(va_list arguments);
int print_number(va_list arguments);
int print_binary(va_list arguments);
int print_unsign(va_list arguments);
int print_octal(va_list arguments);
int print_hex(va_list arguments);
int (*get_func_func(const char s))(va_list);
int print_percent(va_list arguments);
int print_rest(va_list arguments);
void flush_buffer(void);
int handle_write(char c);

#endif
