#include "monty.h"

/**
 * _pall - prints all the values on the stack, starting from top of the stack.
 * @stack: stack to print.
 *
 * Return: (Always Success)
 */
void f_pall(stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (stack->next)
		stack = stack->next;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->prev;
	}
}
