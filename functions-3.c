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

/**
 *_pstr - prints the string starting at the top of the stack,
 *followed by a new line.
 *@stack: linked list
 *@line_number: number of the linked list command
 *
 *Return: nothing, it's a void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if ((*stack) == NULL)
		printf("\n");
	else
	{
		while (temp)
		{
			if (temp->n == 0)
				break;
			else if (temp->n <= 127 && temp->n > 0)
			{
				printf("%c", temp->n);
				temp = temp->next;
			}
			else
				break;
		}
		printf("\n");
	}
}

/**
 *_rotl - swap the first and last value of the linked list
 *@stack: linked list
 *@line_number: number of the linked list command
 *
 *Return: nothing, it's a void
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack)
	{
		value = (*stack)->n;
		while (temp->next != NULL)
		{
			temp->n = temp->next->n;
			temp = temp->next;
		}
		temp->n = value;
	}
}
