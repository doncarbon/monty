#include "monty.h"
/**
 * f_add - adds the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: Nothing (void)
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	f_pop(stack, line_number);
}
