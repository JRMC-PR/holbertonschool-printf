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
	const char newline = '\n';
	print func_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{NULL, NULL}
	};
	va_list args;
	/*strar argument iteration*/
	va_start(args, format);
	while (format != NULL && format[i])
	{
		j = 0;
		while (j < 3)
		{
			if (format[i] == *func_type[j].indi)
			{
				func_type[j].handler(args);
			} /*end if*/
			j++;
		} /*end nested while*/
		i++;
	} /*end outer while*/
	va_end(args);
	_putchar(newline);
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
	int lenght;

	string = va_arg(args, char*);
	/*chec if string is empty*/
	if (args == NULL)
		string = "(nil)";

	lenght = sizeof(string);
	write(1, string, lenght);
} /*end string*/

/**
 *print_mod- a function that prints a %
 *@args: argument of the list
 */
void print_mod(va_list args)
{
	/*variable*/
	char *string;
	/*print value*/
	string = va_arg(args, char*);
	write(1, string, sizeof(string));
} /*end mod*/
