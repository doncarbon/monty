#include "monty.h"

/**
 * read_line - read a single line from the Monty bytecode file
 * @file: file to read from
 * @len: pointer to the length of the buffer
 *
 * Return: 1 on success, 0 on failure
 */
char *read_line(FILE *file, size_t *len)
{
	char *buffer = NULL;
	ssize_t read = getline(&buffer, len, file);

	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}

	return (buffer);
}

/**
 * process_line - process a single line of the Monty bytecode file
 * @line: line to process
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Return: Nothing (void)
 */
void process_line(char *line, stack_t **stack, unsigned int line_number,
		instruction_t *instructions)
{
	char *opcode = strtok(line, " \t\n");
	int i = 0;

	if (opcode != NULL)
	{
		while (instructions[i].opcode)
		{
			if (strcmp(instructions[i].opcode, opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				return;
			}
			i++;
		}

		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		exit(EXIT_FAILURE);
	}
	else
		free(line);
}

/**
 * is_valid_int - check if valid int
 * @str: string to check
 *
 * Return: int
 */
int is_valid_int(const char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);
	return (*endptr == '\0');
}

/**
 * free_stack - free the allocated memory for the stack
 * @stack: pointer to the stack
 *
 * Return: Nothing (void)
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->prev;
		free(temp);
		temp->prev = NULL;
	}
}
