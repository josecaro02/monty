#ifndef MONTY_H
#define MONTY_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *struct v_global - struct to save variables
 *@status: status
 *@n: int that will be save in the linked list
 *@stack: double linked list
 *@line_number: number of the line of the command
 *
 *Description: save variables
 */

typedef struct v_global
{
	int n;
	char *line, *word1, *word2, *name;
	stack_t *stack;
	int isnum;
	FILE *fp;
} va_global;
extern va_global vglobal;
void _push(stack_t **stack, unsigned int line_number);
void free_buffer(char *buffer);
void str_concat(char *s1, char s2);
char *cpy(char *src, char *dest, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_list(stack_t *head);
void _pall(stack_t **stack, unsigned int line_number);
void write_errors(int e_line, unsigned int status);
#endif
