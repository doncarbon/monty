#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_ umber
 * Return: Nothing (void)
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
