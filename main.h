#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int _printf(const char *format, ...);
char *convert_to(char representation[], unsigned int num, int base);
int function_manager(char c, va_list arg);
int _switch(char c, va_list arg);
int loop_format(va_list arg, const char *string);
int call_function_manager(char aux, va_list arg);
int check_percent(int *flag, char aux);

#endif
