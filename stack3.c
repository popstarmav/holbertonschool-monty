#include "monty.h"

/**
 * _pstr - Print the string contained in the stack as ASCII characters
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int c;

	(void)line_number;

	while (current && current->n != 0 && isprint(current->n))
	{
		c = current->n;
		putchar(c);
		current = current->next;
	}

	putchar('\n');
}

/**
 * _rotl - Rotate the stack to the left
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		stack_t *first = *stack;
		stack_t *second = first->next;

		while (first->next)
			first = first->next;

		first->next = *stack;
		(*stack)->prev = first;
		*stack = second;
		(*stack)->prev = NULL;
	}
}

/**
 * _rotr - Rotate the stack to the right
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		stack_t *first = *stack;
		stack_t *last = *stack;

		while (last->next)
			last = last->next;

		last->next = first;
		first->prev = last;
		*stack = last->next;
		(*stack)->prev = NULL;
		last->next = NULL;
	}
}
