#include "main.h"

/**
 *_printf - printf
 *@format: const char pointer
 *Description: this functions implement some functions of printf
 *Return: num of characteres printed
 */

int _printf(const char *format, ...)

{
	const char *string;
	int cont = 0;
	
	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;


	va_end(arg);
	return (cont);
}
