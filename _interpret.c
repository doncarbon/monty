#include "monty.h"

/*
 * interpret : file interpreter
 * @file: file to interpret
 *
 * Return: Nothing (void)
 */
void interpret(FILE *file)
{
	char *lines = NULL, *opcode = NULL, *arg = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	int elem;
	ssize_t line;
	stack_t *stack = NULL;

	while ((line = getline(&lines, &len, file)) != -1)
	{
		line_number += 1;
		opcode = strtok(lines, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (strcmp(opcode, "push") == 0)
		{
			if (arg != NULL)
			{
				if (!isdigit(*arg) && *arg != '-' && *arg != '+')
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				elem = atoi(arg);
				f_push(&stack, elem);
			}
			else
			{
				fprintf(stderr, "L%u: usage: %s integer\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			f_pall(stack);
		}
	}
	free(lines);

	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->prev;
		free(temp);
	}
}
