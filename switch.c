#include <stdarg.h>
#include "main.h"
/**
 * switchFunction - switchs cases of format specifiers
 * @format: is a character string
 * @args: takes in list of arguments
 * Return: returns nothing
 */
void switchFunction(const char *format, va_list args)
{
	int i, num, isCapital = 1;
	char ch, buffer[65];
	const char *s;

	switch (*format)
	{
		case 'c':
		{
			ch = va_arg(args, int);
			_putchar(ch);
			break;
		}
		case 's':
		{
			s = va_arg(args, const char *);
			while (*s)
				_putchar(*s++);
			break;
		}
		case '%':
		{
			_putchar('%');
			break;
		}
		case 'd':
		{
			num = va_arg(args, int);
			signed_integer_to_string(num, 10, isCapital, buffer);
			for (i = 0; buffer[i]; i++)
				_putchar(buffer[i]);
			break;
		}
		case 'i':
		{
			signed_integer_to_string(va_arg(args, int), 10, isCapital, buffer);
			for (i = 0; buffer[i]; i++)
				_putchar(buffer[i]);
			break;
		}
	}
}
