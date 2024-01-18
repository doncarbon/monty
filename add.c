#include "monty.h"
/**
 * f_add - adds the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: Nothing (void)
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int length = 0, alt;

	head = *stack;
	while (head)
	{
		head = head->next;
		length += 1;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	alt = head->n + head->next->n;
	head->next->n = alt;
	*stack = head->next;
	free(head);
}
