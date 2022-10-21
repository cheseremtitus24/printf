#include "main.h"
/**
 * _identify_datatype- Checks for valid format specifiers
 * @fmt: String to be scanned
 * @pos_percent_sign: position to start scanning from for the format specifier
 * @datatype: saves the datatype of the identified format specifier
 * @end_replace_index: Saves position of the last span index of the format
 * specifier
 * @pre_string: Saves contents of the format string before ouputing datatype
 * value
 * @post_string: Saves contents of formatted string that is to the right of
 * datatype value
 *
 * Description- Checks for valid format specifiers and returns the datatype
 *
 * Return: string pointer
 */
char *_identify_datatype(char *fmt,
__attribute__((unused)) int pos_percent_sign,
char *datatype, __attribute__((unused)) int *end_replace_index,
__attribute__((unused)) char *pre_string,
__attribute__((unused)) char *post_string)
{
	__attribute__((unused)) char *s, c;
	__attribute__((unused)) int i, count, counter;
	__attribute__((unused)) double f;
	i = pos_percent_sign;
	count = 0;

	for (; fmt[i] != '\0' && count <= 1; i++)
	{
		switch (fmt[i])
		{
			case 's':              /* string */
				datatype = "string";
				end_replace_index += count;
				return (datatype);
			case 'd':              /* int */
				datatype = "integer";
				end_replace_index += count;
				return (datatype);
			case 'c':              /* char */
				datatype = "character";
				end_replace_index += count;
				return (datatype);
			case 'f':              /* float */
				datatype = "float";
				end_replace_index += count;
				return (datatype);
			case 'i':              /* integer */
				datatype = "integer";
				end_replace_index += count;
				return (datatype);
			case 'u':              /* unsigned int*/
				datatype = "unsigned";
				end_replace_index += count;
				return (datatype);
			default:
				datatype = NULL;
				break;
		}
	}
return (datatype);
}
