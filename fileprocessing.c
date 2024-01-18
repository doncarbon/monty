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
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode = NULL, *arg = NULL;
	instruction_t instructions[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{NULL, NULL}
	};
	int i = 0;
	int found = 0;

	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (arg != NULL)
			{
				if (!is_valid_int(arg))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					free(line);
					exit(EXIT_FAILURE);
				}
				instructions[i].f(stack, atoi(arg));
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(line);
				exit(EXIT_FAILURE);
			}
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		exit(EXIT_FAILURE);
	}
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
