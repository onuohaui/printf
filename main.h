#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct format - Struct for formats
 * @fmt: The format
 * @f: The function associated
 */
typedef struct format
{
	char *fmt;
	int (*f)(va_list);
} format_t;

/* Function Prototypes for format specifiers */

int handle_format_specifier(const char *format,
		va_list args,
		format_t *formats);

/* _printf.c */
int _printf(const char *format, ...);

/* print_char.c */
int print_char(va_list args);

/* print_string.c */
int print_string(va_list args);

/* print_percent.c */
int print_percent(va_list args);

/* print_integer.c */
int print_integer(va_list args);

/* print_unsigned.c */
int print_unsigned(va_list args);

/* print_binary.c */
int print_binary(va_list args);
int print_binary_recursive(unsigned int n);

/* print_address.c */
int print_address(va_list args);
int print_hex_upper(va_list args);
int print_hex(va_list args);

/* print_special_string.c */
int print_special_string(va_list args);

/* print_rot13.c */
int print_rot13(va_list args);

/* print_reverse.c */
int print_reverse(va_list args);

/* Utility Function Prototypes */

char *convert(unsigned int num, int base);
int _putstr(char *str);
int _putchar(char c);

/* print_octal.c */
int print_octal(va_list args);
int print_octal_recursive(unsigned int n);

int print_char_as_hex(unsigned char n);

int print_pointer(va_list args);

int fetch_argument_and_print(char specifier, va_list args, format_t *formats);

/* Buffer-related function prototypes (if implemented) */

int _flush(void);
int _buffer(char c);
int _buffer_string(char *s);

#endif /* MAIN_H */
