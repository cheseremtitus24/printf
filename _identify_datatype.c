#include "main.h"
/**
 * _strcmp- Compares 2 strings for equality
 * @s1: string to compare against
 * @s2: string to compare to
 *
 * Description- Copies string contents of src to dest for a specified length.
 *
 * Return: formatted string
 */
char *_identify_datatype(char *fmt, __attribute__((unused)) int pos_percent_sign, char *datatype, __attribute__((unused)) int *end_replace_index, __attribute__((unused)) char *pre_string, __attribute__((unused)) char *post_string)
{
	/**
	 * This function should perform the formatting
	 * and adds all the necessary data
	 * finally it splits it into 
	 * pre_string and post_string
	 * and returns it to the calling function
	 *
	 *
	 */
	__attribute__((unused)) char *s;
	__attribute__((unused)) int i, count, counter;
	__attribute__((unused)) double f;
	__attribute__((unused)) char c;
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
			/*	s = va_arg(ap, char *);
			 *printf("%s", s);
			 break;
			 */
			case 'd':              /* int */
				datatype = "integer";
				end_replace_index += count;
				return (datatype);
			case 'c':              /* char */
				datatype = "character";
				end_replace_index += count;
				return (datatype);
			case 'f':              /* char */
				datatype = "double";
				end_replace_index += count;
				return (datatype);
			case 'i':              /* char */
				datatype = "integer";
				end_replace_index += count;
				return (datatype);
			case 'u':              /* char */
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
