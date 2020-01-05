#include "monty.h"
/**
 * str_concat - Prints the array reverse
 * @s1: string
 * @s2: string
 *
 * Return: Nothing
 */

void str_concat(char *s1, char s2)
{
	int size1 = 0;

	size1 = strlen(s1);
        s1[size1] = s2;
	s1[size1 + 1] = '\0';

}
