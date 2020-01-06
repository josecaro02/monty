#include "monty.h"

/**
 *_div - divide the top 2 elements of the list
 *@stack: linked list
 *@line_number: number of the linke of the command
 *
 *Return: Nothing, its a void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;
	stack_t *tmp = *stack;
	char string_line[20];

	sprintf(string_line, "%d", line_number);
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%d: division by zero\n", line_number);
			free(vglobal.line);
			fclose(vglobal.fp);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		div = (*stack)->next->n;
		div = div / (*stack)->n;
		(*stack)->next->n = div;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free(vglobal.line);
		fclose(vglobal.fp);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 *_mul - adds the top 2 elements of the list
 *@stack: linked list
 *@line_number: number of the linke of the command
 *
 *Return: Nothing, its a void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;
	stack_t *tmp = *stack;
	char string_line[20];

	sprintf(string_line, "%d", line_number);
	if ((*stack) && (*stack)->next)
	{
		mul = (*stack)->next->n;
		mul = mul * (*stack)->n;
		(*stack)->next->n = mul;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free(vglobal.line);
		fclose(vglobal.fp);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 *_mod - divide the top 2 elements of the list
 *@stack: linked list
 *@line_number: number of the linke of the command
 *
 *Return: Nothing, its a void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;
	stack_t *tmp = *stack;
	char string_line[20];

	sprintf(string_line, "%d", line_number);
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%d: division by zero\n", line_number);
			free(vglobal.line);
			fclose(vglobal.fp);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		mod = (*stack)->next->n;
		mod = mod % (*stack)->n;
		(*stack)->next->n = mod;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free(vglobal.line);
		fclose(vglobal.fp);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}