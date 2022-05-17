#include <stdarg.h>
#include "main.h"

/**
 * v_printf - checks if a percentage specifier is
 *            there and prints
 * @format: is a character string
 * @args: takes in list of arguments
 * Return: returns nothing
 */

void v_printf(const char *format, va_list args)
{
	int state = 0;

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
			{
				state = 1;
			}
			else
			{
				_putchar(*format);
			}
		}
		else if (state == 1)
		{
			switchFunction(format, args);
			state = 0;
		}

		format++;
	}
}
