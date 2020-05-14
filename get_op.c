#include "monty.h"
/**
 * free_function - Free the memory of the linked list.
 * @stack: The token.
 * Return: 0
 */
void free_function(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp == NULL)
			return;
		temp->prev = NULL;
		*stack = temp;
	}
	free(*stack);
}
/**
 * valid_num - Validate the token.
 * @token: The head.
 * Return: 0 if it succeeded, 1 if it failed.
 */
int valid_num(char *token)
{
	unsigned int i;

	if (token == NULL)
		return (1);
	i = 0;
	while (token[i] != '\0')
	{
		if (token[0] == '-')
		{
			if ((!(token[1] >= '0' && token[1] <= '9')) || token[1] == '\0')
				return (0);
			i = 1;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
		else
		{
			i = 0;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}
int arg = 0;

/**
 * get_op - Get the different operations in the monty file.
 * @tokens: The token.
 * @line_num: The current number of the line.
 * Return: 1 if it succeeded, -1 if it failed.
 */
void(*get_op(char **tokens, unsigned int line_num))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_op}, {"pall", pall_op},
		{"pint", pint_op}, {"pop", pop_op},
		{"swap", swap_op}, {"add", add_op},
		{"nop", nop_op},
		{NULL, NULL},
	};
	unsigned int i = 0;

	if (tokens[0][0] == '#')
	{
		free(tokens);
		return (nop_op);
	}

	while (func_arr[i].opcode != NULL)
	{
		if ((strcmp(func_arr[i].opcode, tokens[0]) == 0))
		{
			if ((strcmp(func_arr[i].opcode, "push") == 0) &&
			   (tokens[1] == NULL || (!(valid_num(tokens[1])))))
			{
				free(tokens);
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
			else if ((strcmp(func_arr[i].opcode, "push") == 0))
				arg = atoi(tokens[1]);
			free(tokens);
			return (func_arr[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tokens[0]);
	free(tokens);
	exit(EXIT_FAILURE);
}
