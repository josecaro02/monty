#include "monty.h"
/**
 * free_list - frees memory of a list
 * @head: pointer to head of singly linked list
 *
 * Return: No Return
 */
void free_list(stack_t *head)
{
	if (head)
	{
		free_list(head->next);
		free(head);
	}
}

/**
 *_push - push an int in the linked list
 *@stack: linked list with values
 *@line_number: line number of the command
 *
 *Return: Nothing, it's a void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;

	if (vglobal.isnum == 0)
		write_errors(line_number, 4);
	new = malloc(sizeof(stack_t));
	tmp = *stack;
	if (!new)
		return;

	new->n = vglobal.n;
	if (!tmp)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return;
	}
	tmp->prev = new;
	new->prev = NULL;
	*stack = new;
	new->next = tmp;
}

/**
 *_pall - print all the linked list
 *@stack: linked list with values
 *@line_number: line number of the command
 *
 *Return: Nothing, it's a void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (*stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 *_nop - print all the linked list
 *@stack: linked list with values
 *@line_number: line number of the command
 *
 *Return: Nothing, it's a void
 */
void _nop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	(void) line_number;
}
