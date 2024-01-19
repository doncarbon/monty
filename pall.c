#include "monty.h"

/**
 * f_pall - prints all the values on the stack, starting from top of the stack.
 * @stack: stack to print.
 *
 * Return: (Always Success)
 */
void f_pall(stack_t *stack)
{
	stack_t *temp = stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

