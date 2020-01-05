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
 *Return: 1 success
 */
int _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
		write_errors(3, line_number);
	tmp = *stack;
	new->n = vglobal.n;
	new->next = NULL;
	if (!tmp)
	{	new->prev = NULL;
		*stack = new;
		return (1);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	new->prev = tmp;
	tmp->next = new;
	return (1);

}

/**
 *_pall - print all the linked list
 *@stack: linked list with values
 *@line_number: line number of the command
 *
 *Return: 1 success
 */
int _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (1);
}
