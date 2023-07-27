#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
typedef struct print_struct{
  char *indi;
  int (*handler)(va_list args);
} print;
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_mod(va_list args);
#endif
