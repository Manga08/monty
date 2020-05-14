#include "monty.h"
/**
 * mod_op - Computes division remainder from top two stack elements.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
/**
 * pchar_op - Prints the char at the top of the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
/**
 * pstr_op - Prints the string starting at the top of the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
/**
 * rotl_op - Rotates the stack to the top.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (*stack && (*stack)->next)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
/**
 * rotr_op - Rotates the stack to the bottom.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (*stack && (*stack)->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *stack;
		(*stack)->prev = temp;
		temp->prev->next = NULL;
		temp->prev = NULL;
		*stack = temp;
	}
}
