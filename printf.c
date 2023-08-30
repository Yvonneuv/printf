#include "main.h"

//writing a function that produces an output according to the format//

/**
 * _printf - Returns the number of characters printed.
 * @c: character
 * @s: string
 * @%: special character specifier.
 * Return: 0 always.
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list list of args;

	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
			format++;
		if (*format == '\0')
			break;

		if (*format == '%')//for double% char
		{
			write(1, format, 1);
			char_print++;
		}

		else if (*format == 's')//for s char
		{
			char *str = var_arg(list_of_args,char*);
			int str_len = 0;

			while (str[str_len] != '0')//gets length s
				str_len++;
			write(1, str, str_len);//writes string to outp
			char_print += str_len;
		}
		else if (*format == 'c')//for c char
		{
			char c = va_arg(list of args, int);
			write(1, &c, 1);
			char_print++;
		}
	}
	format++;

	va_end( list of args);

	return(char_print)
}

