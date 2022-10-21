#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _print_floats- prints a float as a string
 * @val: float value to print
 *
 * Description- outputs a float as a string
 * to function _puts_recursion(s)
 *
 * Return: void
 */
void _print_floats(float val, int *prints_counter)
{
	char buffer[11];
	int slen;

	gcvt(val, 6, buffer);
	buffer[10] = 0;
	slen = _strlen_recursion(buffer) + 1;
	write(1, buffer, slen);
	*prints_counter += slen - 1;
}
