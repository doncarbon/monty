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
 * handle_error - handle error messages.
 * @message: error message
 * @line_number: line number
 * @line: line where the error is
 *
 * Return: void.
 */
void handle_error(const char *message, unsigned int line_number, char *line)
{
	fprintf(stderr, "L%u: %s\n", line_number, message);
	free(line);
	exit(EXIT_FAILURE);
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

	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");
	if (!opcode)
		return;
	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || (!isdigit(*arg) && *arg != '-' && *arg != '+'))
			handle_error("usage: push integer", line_number, line);
		f_push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
		f_pall(*stack);
	else if (strcmp(opcode, "pint") == 0)
		f_pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		f_pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		f_swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		f_add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		f_nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		f_sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		f_div(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		f_mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		f_mod(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		exit(EXIT_FAILURE);
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
