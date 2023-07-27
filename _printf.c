#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - a function that behaves like the stdio.h printf();
 * @format: points to a constant format list
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, found = 0, printed_chars = 0;
	print func_type[] = {{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{"d", print_int},
		{"i", print_int}};
	va_list args;

	va_start(args, format);
	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			for (j = 0; j < 5; j++)
			{
				if (format[i + 1] == *func_type[j].indi)
				{
					printed_chars += func_type[j].handler(args);
					i++; /* Skip the next character when % is found */
					found = 1; /*boolian*/
					break;
				} /*end if*/
			} /*end inner while*/
			if (!found)
			{
				_putchar('%');
				printed_chars++;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		} /*end outer if else*/
		i++;
	} /*en douter while*/
	va_end(args);
	return (printed_chars);
} /*end function*/

