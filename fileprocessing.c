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
	int elem;

	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (arg != NULL)
			{
				if (!isdigit(*arg) && *arg != '-' && *arg != '+')
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					free(line);
					exit(EXIT_FAILURE);
				}
				elem = atoi(arg);
				f_push(stack, elem);
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
			f_pall(*stack);
		else if (strcmp(opcode, "pint") == 0)
			f_pint(stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			f_pop(stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			f_swap(stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
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

		stack = stack->next;
		free(temp);
	}
}
