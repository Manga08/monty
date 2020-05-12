#include "monty.h"
/**
 * enterfile - Enter and read the monty file
 * @montyfile: Monty file
 */

void enterfile(char *montyfile)
{
	FILE *file;
	file = fopen(montyfile, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", montyfile);
		exit(EXIT_FAILURE);
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
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        enterfile(argv[1]);
        return (0);
}
