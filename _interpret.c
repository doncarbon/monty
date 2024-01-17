#include "monty.h"
/*
 * interpret : file interpreter
 * @file: file to interpret
 *
 * Return: Nothing (void)
 */
void interpret(FILE *file)
{
	char *line= NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	int elem;
	stack_t *stack = malloc(sizeof(stack_t));
	stack->next = NULL;
	stack->prev = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number += 1;
		char *opcode = strtok(line, " \t\n");
		char *arg = strtok(NULL, " \t\n");
	}
	if (strcmp(opcode, "push") == 0)
	{
		if (arg != NULL)
		{
			elem = atoi(arg);
			f_push(&stack, elem);
		}
		else
		{
			fprintf(stderr, "L%u: usage: %s integer\n", line_number, opcode);
		}
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		f_pall(&stack);
	}
}
