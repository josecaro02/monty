#include "monty.h"
/**
 * free_buffer - writes the character c to stdout
 * @buffer: The character to print
 *
 * Return: nothing
 */
void free_buffer(char *buffer)
{
	int len = strlen(buffer);
	int i;

	for (i = 0; i < len; i++)
	{
		buffer[i] = 0;
	}
	free(buffer);
}
