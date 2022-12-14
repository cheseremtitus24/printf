#include "main.h"
#include <stdio.h>
/**
 * _puts_recursion- prints a string
 * @s: string to print
 * @print_counter: tracks the number of characters being printed
 *
 * Description- outputs a string using recursive calls
 * to function _puts_recursion(s)
 *
 * Return: void
 */
void _puts_recursion(char *s, int *print_counter)
{
	if (*s == '\0')
	{
		/*_putchar('\n');*/
		return;
	}
	_putchar(*s);
	s = s + 1;
	*print_counter += 1;
	_puts_recursion(s, print_counter);

}

