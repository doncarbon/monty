#include "monty.h"

/**
 * main - Entry point for the Monty Program.
 * @argc: command-line arguments count.
 * @argv: command-line arguments.
 *
 * Return: (Always success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	instruction_t instructions[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpret(file, instructions);
	fclose(file);
	return (EXIT_SUCCESS);
}
