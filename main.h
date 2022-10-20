
#ifndef _MAIN_H_
#define _MAIN_H_
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/*Basic Helper Functions */
int _putchar(char c);
int _strlen_recursion(char *s);
int _strcmp(char *s1, char *s2);
int _strchr(char *s, int *scan_index,
char c, int *counted, int *print_char_counter);
char *scan_symbol_strchr(char *s, int *scan_index, char c, int *counted);
int _strchr(char *s, int *scan_index, char c,
int *counted, int *print_char_counter);
void _print_number(int n, int *print_counter);
void _print_floats(float val);
void _puts_recursion(char *s, int *print_counter);
int _atoi(char *s);
/* turn on and off the scanning of forward slashes and percentage sign char's*/
void switch_off(short int *scan_flag);
void switch_on(short int *scan_flag);

/* End of Basic Helper Functions */

int _printf(char *fmt, ...);

char *_identify_datatype(char *fmt,
__attribute__((unused)) int pos_percent_sign, char *datatype,
__attribute__((unused)) int *end_replace_index,
__attribute__((unused)) char *pre_string,
__attribute__((unused)) char *post_string);

int (*get_op_func(char *s))(int, int);
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/*
 * Structs, enums and unions definitions
 * Typedefs
 * Function prototypes
 */

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;


#endif /* _MAIN_H_ */
