#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * _printf - a function that behaves like the stdio.h printf();
 * @format: points to a constant format list
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list args;
	int (*this_thing)(va_list);

	va_start(args, format);
	if (format != NULL)
	{
		if (format == NULL || (format[0] == '%' && format[1] == '\0'))
			return (-1);
		while (format != NULL && format[i])
		{
			if (format[0] == '%' && format[1] == '\0')
				return (-1);
			while (format != NULL && format[i] != '\0')
			{
				if (format[i] == '%')
				{
					while (format[i + 1] == ' ')
						i++;
					if (format[i + 1] == '%')
					{
						printed_chars += _putchar(format[i]);
						i += 2;
					}
					else
					{
						this_thing = get_print(format[i + 1]);
						if (this_thing)
							printed_chars += this_thing(args);
						else
							printed_chars = _putchar(format[i]) + _putchar(format[i + 1]);
						i += 2;
					} /*end if else*/
				} /*end if */
				else
				{
					printed_chars += _putchar(format[i]);
					i++;
				} /*end outer if else*/
			} /*en douter while*/
			va_end(args);
			return (printed_chars);
		}
	} /*end function*/
	return (-1);
}

