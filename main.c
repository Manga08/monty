#include "monty.h"
/**
 * main - Main function
 * @argc: Number of the arguments
 * @argv: Arguments Received
 * Return: 0 or Exit on failure
 */

int main(int agrc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	entefile(argv[1]);
	return (0);
}

/**
 * enterfile - Enter and read the monty file
 * @montyfile: Monty file
 */

void enterfile(char *montyfile)
{
	file = fopen(montyfile, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", montyfile);
		exit(EXIT_FAILURE);
	}
}
