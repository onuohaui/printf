#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
struct print
{
	char *t;
	int (*f)(va_list);
};

int _printf(const char *format, ...);
int _putchar(char c);

/* Print Functions */

int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_int(va_list);
int print_unsigned(va_list);
int print_octal(va_list);
int print_hex(va_list);
int print_hex_big(va_list);
int print_binary(va_list);
int print_rev_string(va_list);
int print_rot13(va_list);
int print_ptr(va_list);
int print_nonprint_char(va_list);

/* Helper Functions */
char utoa(unsigned int, char, int);
char itoa(int, char, int);
void reverse_string(char *);
void rot13(char *);
void print_buffer(char *, int);

/* Macro for buffer size */
#define BUFF_SIZE 1024

#endif /* MAIN_H */
