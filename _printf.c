#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 *_printf - a funtion that behaves like the stdio.h printf();
 *@format: points to a constant format list
 *Return: 0 or result
 */
int _printf(const char *format, ...)
{
	/*Variables*/
	unsigned int i = 0, j = 0;
	int count = 0;
	print func_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{'\0', NULL}
	};
	va_list args;
	/*strar argument iteration*/
	va_start(args, format);
	if (format == NULL)
	{
		return (1);
	}
	else
	{
		while (format[i] != '\0')
		{
			j = 0;
			if (format[i] == '%')
			{
				i++;
				while (format[i] != *func_type[j].indi)
				{
					if (format[i] == *func_type[j].indi)
					{
						count += func_type[j].handler(args);
						i++;
						break;
					}
					j++;
				} /*end inner while*/
			} /*end if*/
			else
			{
				write(1, &format[i], strlen(format));
				count++;
				return (count);
			} /*end if else*/
			i++;
		} /*end inner while*/
		/*Mark end or varidic and return count*/
		va_end(args);
		return (count);
	} /*end if else for format*/
} /*end function*/

