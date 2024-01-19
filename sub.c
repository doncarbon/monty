#include "monty.h"
/**
 * f_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: stack head
 * @line_number: line number
 *
 * Return: Nothing (void)
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	f_pop(stack, line_number);
}
