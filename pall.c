#include "monty.h"

/**
 * _pall - prints all the values on the stack, starting from top of the stack.
 * @stack: stack to print.
 *
 * Return: (Always Success)
 */
void _pall(stack_t *stack)
{
	if (stack == NULL)
		return (0);

	while (stack->next)
		stack = stack->next;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->prev;
	}
}
