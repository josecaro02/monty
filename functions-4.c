#include "monty.h"

/**
 *_rotr - swap the first and last value of the linked list
 *@stack: linked list
 *@line_number: number of the linked list command
 *
 *Return: nothing, it's a void
*/
void _rotr(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack)
	{
		while (temp->next != NULL)
			temp = temp->next;
		value = temp->n;
		while (temp->prev != NULL)
		{
			temp->n = temp->prev->n;
			temp = temp->prev;
		}
		temp->n = value;
	}
}
