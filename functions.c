#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 *print_char- a function that prints a char
 *@args: argument of the list
 */
int print_char(va_list args)
{
	int the_thing, count = 0;
	the_thing = va_arg(args, int);
	write(1, &the_thing, 1);
	count++;
	return (count);
} /*end char*/

/**
 *print_string- a function that prints an string
 *@args: argument of the list
 */
int print_string(va_list args)
{
	/*Variables*/
	char *string = va_arg(args, char*);
	int count = 0;

	/*chec if string is empty*/
	if (args == NULL)
		string = "(nil)";
	/*print every char*/
	write(1, string, strlen(string));
	count++;
	return (count);
} /*end string*/

/**
 *print_mod- a function that prints a %
 *@args: argument of the list
 */
int  print_mod(va_list args)
{
	/*variable*/
	char mod = va_arg(args, int);
	int count = 0;
	/*print value*/
	write(1, &mod, 1);
	count++;
	return (count);
} /*end mod*/

