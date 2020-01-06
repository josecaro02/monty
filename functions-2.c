#include "monty.h"

/**
 *_pint - removes the first element of the linked list
 *@stack: linked list with values
 *@line_number: number of the line with the command
 *
 *Return: nothing, it's a void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	char string_line[20];
	stack_t *tmp = *stack;

	sprintf(string_line, "%d", line_number);
	if (*stack)
		printf("%d\n", tmp->n);
	else
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free(vglobal.line);
		fclose(vglobal.fp);
		exit(EXIT_FAILURE);
	}
}

/**
 *_pop - removes the first element of the linked list
 *@stack: linked list with values
 *@line_number: number of the line with the command
 *
 *Return: nothing, it's a void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	char string_line[20];

	sprintf(string_line, "%d", line_number);
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free(vglobal.line);
		fclose(vglobal.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
		*stack = NULL;
}

/**
 *_swap - swap the top 2 elements of the list
 *@stack: linked list
 *@line_number: number of the linke of the command
 *
 *Return: Nothing, its a void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int value;
	char string_line[20];

	sprintf(string_line, "%d", line_number);
	if ((*stack)->n && (*stack)->next->n)
	{
		value = (*stack)->next->n;
		(*stack)->next->n = (*stack)->n;
		(*stack)->n = value;
	}
	else
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free(vglobal.line);
		fclose(vglobal.fp);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 *_add - adds the top 2 elements of the list
 *@stack: linked list
 *@line_number: number of the linke of the command
 *
 *Return: Nothing, its a void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp = *stack;
	char string_line[20];

	sprintf(string_line, "%d", line_number);
	if((*stack)->n && (*stack)->next->n)
	{
		sum = (*stack)->next->n;
		sum = sum + (*stack)->n;
		(*stack)->next->n = sum;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(2,"L%d: can't add, stack too short\n", line_number);
                free(vglobal.line);
                fclose(vglobal.fp);
                free_list(*stack);
		exit(EXIT_FAILURE);
	}
}
