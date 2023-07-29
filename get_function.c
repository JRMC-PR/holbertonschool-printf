#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 *get_print- gets function to be used
 *@format: format to compare
 *Return: function or null
 */
int (*get_print(char format))(va_list)
{
	/*Variables*/
	int i = 0;
	print func_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	/*finding functions*/

	while (func_type[i].indi)
	{
		if (format == func_type[i].indi[0])
			return (func_type[i].handler);
		i++;
	}
	return (NULL);
}


