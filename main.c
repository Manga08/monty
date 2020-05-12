#include "monty.h"

/**
 * tokenize - Tokenize a line in to tokens, only get two first tokens
 * @buffer: Buffer
 * Return:  Tokens, or NULL if failed
 */

char **tokenize(char *buffer)
{
	char *token, **tokens;
	unsigned int i;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " '\n'");
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	i = 0;
	while (token != NULL && i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, " '\n'");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * enterfile - Enter and read the monty file
 * @montyfile: Monty file
 * @buffer: Buffer
 * @size: Size of the buffer
 * Return: void
 */

void enterfile(char *montyfile, char *buffer, size_t size)
{
	FILE *file;
	int line_num = 0;
	stack_t *stack = NULL;
	char **tokens;

	file = fopen(montyfile, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", montyfile);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, file) != -1)
	{
		line_num++;
		tokens = tokenize(buffer);
		if (tokens != NULL)
			get_op(&stack, tokens, line_num);
	}
	fclose(file);
}

/**
 * main - Main function
 * @argc: Number of the arguments
 * @argv: Arguments Received
 * Return: 0 or Exit on failure
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	enterfile(argv[1], buffer, size);
	return (0);
}
