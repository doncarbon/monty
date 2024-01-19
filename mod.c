#include "monty.h"

/**
 * f_mod - computes the rest of the division of the 2nd top element by the 1st.
 * @stack: stack to be operated on
 * @line_number: line number in the file
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	f_pop(stack, line_number);
}
