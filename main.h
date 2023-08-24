#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int _printf_char(const char *format, va_list args);
int _printf_string(const char *format, va_list args);
int _printf_int(const char *format, va_list args);
int _printf_unsigned(const char *format, va_list args);

int _printf_flag_plus(const char *format, va_list args);
int _printf_flag_space(const char *format, va_list args);
int _printf_flag_hash(const char *format, va_list args);
int _printf_length_modifier_l(const char *format, va_list args);
int _printf_length_modifier_h(const char *format, va_list args);

int _printf_custom_r(const char *format, va_list args);

#endif /* MAIN_H */
