#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_ umber
 * Return: Nothing (void)
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
