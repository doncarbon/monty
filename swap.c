#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_ umber
 * Return: Nothing (void)
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int length, alt;

	head = *stack;
	while (head)
	{
		head = head->next;
		length += 1;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	alt = head->n;
	head->n = head->next->n;
	head->next->n = alt;
}
