#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Include the va_list type for variable arguments */

/* Define the struct print */
typedef struct print_struct
{
char *indi;
void (*handler)(va_list agrs);
} print;

/* Function prototypes for _printf and additional functions */
int _printf(const char *format, ...);
void print_char(va_list args);
void print_string(va_list args);
void print_mod(va_list args);
void print_int(va_list args);
int _putchar(char c);

#endif

