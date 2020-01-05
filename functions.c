#include "monty.h"
/**
 * free_dlistint - frees memory of a list
 * @head: pointer to head of singly linked list
 *
 * Return: No Return
 */
void free_list(stack_t *head)
{
	if (!head)
		return;
	free_list(head->next);
	free(head);
}
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;
	int a;
	new = malloc(sizeof(stack_t));
	if (!new)
		write_errors(3, line_number);
	tmp = *stack;
	new->n = atoi(vglobal.n);
	new->next = NULL;
	if (!tmp)
	{	new->prev = NULL;
		*stack = new;
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	new->prev = tmp;
	tmp->next = new;

}
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
