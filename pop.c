#include "monty.h"
/**
 * f_pop - removes the top element of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: Nothing (void)
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = head->next;
	free(head);
}
