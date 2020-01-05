#include "monty.h"


va_global vglobal;
void start_varglobal(void);
/**
 * _strdup - Prints the array reverse
 * @str: string
 *
 * Return: Nothing
 */

char *_strdup(char *str)
{
	int i, size;
	char *dest;

	if (str == 0)
	{
		return (NULL);
	}
	for (size = 0; str[size] != 0; size++)
	{}
	dest = malloc((size + 1) * sizeof(char));
	if (dest == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - Compares two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: The pointer to dest
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 - *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
void write_errors (int e_line, int status)
{
	char string_line[20];
	sprintf(string_line, "%d", e_line);
	if (status == 1)
		write(2, "Error: Can't open file <file>\n",30);
	if (status == 2)
	{
		write(2, "L",1);
		write(2, string_line, strlen(string_line));
		write(2, ": unknown instruction <opcode>\n",32);
	}
	if (status == 3)
	{
		write(2, "Error: malloc failed", 20);
	}
	exit(EXIT_FAILURE);
}
void get_words(char *line, char **word1, char **word2, int e_line)
{
	*word1 = malloc(5);
	*word2 = malloc(500);
	if (!*word1 || !*word2)
		write_errors(e_line, 3);
	int i;
	for (i = 0; line[i]; i++)
	{
		if (line[i] >= 48 && line[i] <= 57 && !strlen(*word1))
			write_errors(e_line, 2);
		if (line[i] == ' ' && strlen(*word1) != 0)
			break;
		if (line[i] == ' ')
			continue;
		if (line[i] > 96 && line[i] < 123)
			str_concat(*word1, line[i]);
	}
	for(;line[i];i++)
	{
		if (line[i] > 96 && line[i] < 123 && !strlen(*word2))
                        write_errors(e_line, 2);
                if (line[i] == ' ' && strlen(*word2) != 0)
                        break;
		if (line[i] == ' ')
                        continue;
		if (line[i] >= 48 && line[i] <= 57)
			str_concat(*word2, line[i]);
	}
}

int main(int argc, char **argv[])
{
	int i;
	FILE *fp;
	unsigned int count = 1;
	char *line, *word1, *word2, *cpy;
	size_t len = 0;
	instruction_t functions[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	stack_t *stack = NULL;
	word1 = word2 = NULL;
	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen((const char*)argv[1], "r");
	if (fp == NULL)
		write_errors(count, 1);
	while(getline(&line, &len, fp) != -1)
	{
		get_words(line, &word1, &word2, count);
		vglobal.n = word2;
		for (i = 0; functions[i].opcode != NULL; i++)
		{
			if(!_strcmp(word1, functions[i].opcode))
			{
				functions[i].f(&stack, count++);
			}
		}
		free_buffer(word1);
		free_buffer(word2);
	}
	free_buffer(line);
	fclose(fp);
	free_list(stack);
}
void set_global(void)
{
	vglobal.status = 0;
	vglobal.n = NULL;
	vglobal.stack = NULL;
	vglobal.line_number = 0;
}
