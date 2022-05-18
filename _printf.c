<<<<<<< HEAD
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
	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	cont = loop_format(arg, string);

	va_end(arg);
	return (cont);
}

/**
 *loop_format - loop format
 *@arg: va_list arg
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 *Return: num of characteres printed
 */

int loop_format(va_list arg, const char *string)

{

		int i = 0, flag = 0, cont_fm = 0, cont = 0, check_per = 0;

		while (i < strlen((char *)string) && *string != '\0')
		{
			char aux = string[i];

			if (aux == '%')
			{
				i++, flag++;
				aux = string[i];
				if (aux == '\0' && strlen((char *)string) == 1)
					return (-1);
				if (aux == '\0')
					return (cont);
				if (aux == '%')
				{
					flag++;
				} else
				{
					cont_fm = function_manager(aux, arg);
					if (cont_fm >= 0 && cont_fm != -1)
					{
						i++;
						aux = string[i];
						if (aux == '%')
							flag--;
						cont = cont + cont_fm;
					} else if (cont_fm == -1 && aux != '\n')
					{
						cont += _putchar('%');
					}
				}
			}
			check_per = check_percent(&flag, aux);
			cont += check_per;
			if (check_per == 0 && aux != '\0' && aux != '%')
				cont += _putchar(aux), i++;
			check_per = 0;
		}
		return (cont);
}

/**
 * check_percent - call function manager
 *@flag: value by reference
 *@aux: character
 *Description: This function print % pear
 *Return: 1 if % is printed
 */

int check_percent(int *flag, int aux)

{
	int tmp_flag;
	int cont = 0;

	tmp_flag = *flag;
	if (tmp_flag == 2 && aux == 'c')
	{
		_putchar('c');
		tmp_flag = 0;
		cont = 1;
	}
	return (cont);
}

/**
 * call_function_manager - call function manager
 *@aux: character parameter
 *@arg: va_list arg
 *Description: This function call function manager
 *Return: num of characteres printed
 */

int call_function_manager(char aux, va_list arg)

{
	int cont = 0;

	cont = function_manager(aux, arg);
	return (cont);
=======
#include "holberton.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
>>>>>>> efeee81025c58f972e73dd7738fbb123833eab9c
}
