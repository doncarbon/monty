#include "monty.h"
/**
 * f_pop - removes the top element of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: Nothing (void)
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->prev;
	free(temp);
	if (*stack != NULL)
		(*stack)->next = NULL;
}
