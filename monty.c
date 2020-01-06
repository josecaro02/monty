#include "monty.h"
/**
 * _isnumber - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int _isnumber(char *s)
{
	if (!*s)
		return (0);

	if (*s == '-')
		s++;

	for (; *s; s++)
		if (!isdigit(*s))
			return (0);
	return (1);
}
va_global vglobal;
void start_varglobal(void);
/**
 *write_errors - print different error messages deppend the case
 *@e_line: number of the line of the error
 *@status: identifier of the error
 *
 *Return: Nothing, it's a void function
 */
void write_errors(int e_line, unsigned int status)
{
	if (status == 1)
	{
		dprintf(2, "Error: Can't open file %s\n", vglobal.name);
		exit(EXIT_FAILURE);
	}
	if (status == 2)
		dprintf(2, "L%d: unknown instruction %s\n", e_line, vglobal.word1);
	if (status == 3)
		dprintf(2, "Error: malloc failed\n");
	if (status == 4)
	{
		dprintf(2, "L%d: usage: push integer\n", e_line);
	}
	if (status == 5)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	free_buffer(vglobal.line);
	fclose(vglobal.fp);
	free_list(vglobal.stack);
	exit(EXIT_FAILURE);
}

/**
 *get_words - find the first two words of a line of characters
 *@e_line: Number of the line of the command
 *
 *Return: Nothing, it's a void function
 */
void get_words(int e_line)
{
	int i;
	char comment;

	vglobal.word2 = malloc(500);
	if (!vglobal.word1 || !vglobal.word2)
		write_errors(e_line, 3);
	for (i = 0; vglobal.line[i]; i++)
	{
		comment = vglobal.line[i];
		if (comment == 35)
		{
			str_concat(vglobal.word1, 'n');
			str_concat(vglobal.word1, 'o');
			str_concat(vglobal.word1, 'p');
			return;
		}
		else if (comment == 32)
			continue;
		else
			break;
	}
	for (i = 0; vglobal.line[i]; i++)
	{
		if (vglobal.line[i] >= 48 && vglobal.line[i] <= 57 && !strlen(vglobal.word1))
			write_errors(e_line, 2);
		if (vglobal.line[i] == ' ' && strlen(vglobal.word1) != 0)
			break;
		if (vglobal.line[i] == ' ')
			continue;
		if (vglobal.line[i] > 96 && vglobal.line[i] < 123)
		{
			str_concat(vglobal.word1, vglobal.line[i]);
		}
	}
	for (; vglobal.line[i]; i++)
	{
		if (vglobal.line[i] == ' ' && strlen(vglobal.word2) != 0)
			break;
		if (vglobal.line[i] == ' ')
			continue;
		if (vglobal.line[i] >= 48 && vglobal.line[i] <= 57)
			str_concat(vglobal.word2, vglobal.line[i]);
		if (vglobal.line[i] > 96 && vglobal.line[i] < 123)
			str_concat(vglobal.word2, vglobal.line[i]);
		if (vglobal.line[i] == '-')
			str_concat(vglobal.word2, vglobal.line[i]);
	}
}

/**
 *main - man function of the monty interprete program
 *@argc: quantity of given arguments
 *@argv: array of strings of the given arguments
 *
 *Return: 0 success
 */
int main(int argc, char *argv[])
{
	int i, tmp = 1;
	unsigned int count = 1;
	size_t len = 0;
	instruction_t functions[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{NULL, NULL}
	};
	if (argc != 2)
		write_errors(count, 5);
	vglobal.name = argv[1];
	vglobal.fp = fopen((const char *)argv[1], "r");
	if (vglobal.fp == NULL)
		write_errors(count, 1);
	while (getline(&(vglobal.line), &len, vglobal.fp) != -1)
	{
		if (vglobal.line[0] == '\n')
			continue;
		get_words(count);
		vglobal.isnum = _isnumber(vglobal.word2);
		vglobal.n = atoi(vglobal.word2);
		free_buffer(vglobal.word2);
		for (i = 0; functions[i].opcode != NULL; i++)
		{
			if (strcmp(vglobal.word1, functions[i].opcode) == 0)
			{
				tmp = 0;
				functions[i].f(&(vglobal.stack), count);
				break;
			}
		}
		if (tmp != 0)
			write_errors(count, 2);
		tmp = 1;
		count++;
		vglobal.word1[0] = '\0';
	}
	free_buffer(vglobal.line);
	fclose(vglobal.fp);
	free_list(vglobal.stack);
	return (0);
}

/**
 *set_global - set global variables
 *
 *Return: Nothing, it's a void
 */
void set_global(void)
{
	vglobal.n = 0;
	vglobal.isnum = 0;
	vglobal.word1[0] = '\0';
	vglobal.word2 = NULL;
	vglobal.line = NULL;
	vglobal.fp = NULL;
	vglobal.stack = NULL;
	vglobal.name = NULL;
}
