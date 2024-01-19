#include "monty.h"
/**
 * f_div - divides the second top element of the stack by the top element.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Return: Nothing (Always success)
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    f_pop(stack, line_number);
}
