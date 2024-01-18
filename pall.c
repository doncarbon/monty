#include "monty.h"

/**
 * f_pall - prints all the values on the stack, starting from top of the stack.
 * @stack: stack to print.
 * @line_number: line number
 *
 * Return: (Always Success)
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	head = *stack;
	if (head == NULL)
	{
		return;
	}

	while (head->next)
		head = head->next;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
}
