#include "monty.h"

/**
 * interpret - file interpreter
 * @file: file to interpret
 *
 * Return: Nothing (void)
 */
void interpret(FILE *file, instruction_t *instructions)
{
	char *lines = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while ((lines = read_line(file, &len)) != NULL)
	{
		line_number += 1;
		process_line(lines, &stack, line_number, instructions);
		free(lines);
	}

	free_stack(stack);
}
