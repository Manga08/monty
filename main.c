#include "monty.h"
/**
 * enterfile - Enter and read the monty file
 * @montyfile: Monty file
 */

void enterfile(char *montyfile, char *buffer, size_t size)
{
	FILE *file;
	int line_num = 0;
	stack_t *stack = NULL;
	char *token;

	file = fopen(montyfile, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", montyfile);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, file) != -1)
	{
		token = strtok(buffer, " \t");
		if (token[0] != '\n')
			get_op(&stack, token, line_num);
		line_num++;
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
