#include "monty.h"
/**
 * f_mul - multiplies the second top element of the stack with the top element
 * @stack: stack to be operated on
 * @line_number: line number in the file
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    f_pop(stack, line_number);
}
