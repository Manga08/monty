#include "monty.h"

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


void(*get_op(char **tokens, unsigned int line_num))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL},
	};
	int i = 0;

	while(func_arr[i].opcode != NULL)
	{
		if ((strcmp(func_arr[i].opcode, tokens[0]) == 0))
		{
			if ((strcmp(func_arr[i].opcode, "push") == 0) &&
			   (tokens[1] == NULL || ((valid_num(tokens[1]) == 0))))
			{
				free(tokens);
				fprintf(stderr,"L%d: usage: push integer", line_num);
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
