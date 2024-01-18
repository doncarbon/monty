#include "monty.h"

/**
 * _push - pushes an element to the stack.
 * @stack: stack to be edited.
 * @element: Element to push.
 *
 * Return: (Always success)
 */
void f_push(stack_t **stack, int element)
{
	stack_t *temp = malloc(sizeof(stack_t));
	stack_t *top = NULL;

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->prev = NULL;
	temp->n = element;
	temp->next = NULL;
	top = *stack;

	if (top != NULL)
		while (top->next)
			top = top->next;

	temp->prev = top;
	if (top != NULL)
		top->next = temp;

	*stack = temp;
}
