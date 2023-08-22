#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_specifier(char spec, va_list args, char *buffer, int len);
char *int_to_string(int n, char *buffer);
int _putchar(char c);
void print_char(va_list args);
void print_string(va_list args);
void print_percent(void);
int _print_string(char *s);


#endif /* MAIN_H */
