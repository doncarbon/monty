#include "monty.h"

/**
 * f_pint - prints the value at the top of the stack.
 * @stack: stack to print.
 * @linenum: Number of the line.
 *
 * Return: (Always Success)
 */
void f_pint(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		*stack = (*stack)->next;

	printf("%d\n", (*stack)->n);
}
