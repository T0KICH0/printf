#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 *         (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int noSpecifier = 1, length = 0, isPercentage = 0;
	const char *s = format, *s1 = format;
	va_list args;

	while (*s1)
	{
		if (*s1 == '%')
		{
			noSpecifier = 0;
			break;
		}
		s1++;
	}
	while (*s1)
	{
		if (*s1 == '%' && *(s1 + 1) == '%')
			isPercentage = 1;
		s1++;
	}
	va_start(args, format);

	if (!noSpecifier)
		v_printf(format, args);
	else
	{
		while (*s)
		{
			_putchar(*s);
			s++;
		}
	}

	va_end(args);
	for (length = 0; *format != '\0'; format++)
		length++;
	if (isPercentage)
		return (length - 1);
	else
		return (length);
}
