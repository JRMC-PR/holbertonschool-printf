#include "main.h"
#include <stdioh>
#include <unistd.h>
/**
 *_printf - a funtion that behaves like the stdio.h printf();
 *@format: points to a constant format list
 *Return: 0 or result
 */
int _printf(const char *format, ...)
{
	/*Variables*/
	unsigned int i = 0, j = 0;
	print funct_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{NULL, NULL}
	};
	va_list agrs
	/*strar argument iteration*/
	va_start(args, format);
	while (format != NULL && format[i])
	{
		j = 0;
		while (j < 3)
		{
			if (format[i] == *func_type[j].indi)
			{
				func_type[j].handler(args)
			} /*end if*/
			j++;
		} /*end nested while*/
		i++;
	} /*end outer while*/
	va_end(args);
	_putchar("\n");
	return (0);
} /*end function*/

/**
 *print_char- a function that prints a char
 *@args: argument of the list
 */
void print_char(va_list args)
{
	_putchar(va_arg(args, int));
} /*end char*/

/**
 *print_string- a function that prints an string
 *@args: argument of the list
 */
void print_string(va_list args)
{
	/*Variables*/
	char *string;

	string = va_arg(args, char*);
	/*chec if string is empty*/
	if (args == NULL)
		string = "(nil)";
	write(STDOUT_FILENO, string, strlen(string));
} /*end string*/

/**
 *print_mod- a function that prints a %
 *@args: argument of the list
 */
void print_mod(va_list args)
{
	/*variable*/
	char *string;

	string = va_arg(args, int);
	write(STDOUT_FILENO, string, strlen(string));
} /*end mod*/

