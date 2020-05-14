#include "monty.h"
/**
 * push_op - Pushes an element to the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	if (*stack == NULL)
		new_node->next = NULL;
	else
		new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}
/**
 * pall_op - Prints all the values on the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	const stack_t *ptr;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * pint_op - Prints the value at the top of the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop_op - Removes the top element of the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap_op - Prints the value at the top of the stack.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
