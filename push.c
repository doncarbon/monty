#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 * @stack: stack to be edited.
 * @element: Element to push.
 *
 * Return: (Always success)
 */
void f_push(stack_t **stack, int element)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->prev = NULL;
	temp->n = element;
	temp->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = temp;

	*stack = temp;
}
