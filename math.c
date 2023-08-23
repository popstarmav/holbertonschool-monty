#include "monty.h"

/**
 * _sub - Subtract the top element of the stack from the second top element
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * _mul - Multiply the top element of the stack with the second top element
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = aux;
}

/**
 * _div - Divide the second top element of the stack by the top element
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		if ((*stack)->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		else
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * _mod - Compute the modulo of the second top element by the top element
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		if ((*stack)->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		else
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = mod;
}
