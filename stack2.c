#include "monty.h"

/**
 * _swap - Swap the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		handle_error_at_line(line_number, "can't swap, stack too short\n");

	int tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * _add - Add the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		handle_error_at_line(line_number, "can't add, stack too short\n");

	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _nop - Do nothing
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _pchar - Print the ASCII value of the top element in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		handle_error_at_line(line_number, "can't pchar, stack empty\n");

	int val = (*stack)->n;

	if (val < 0 || val > 127)
		handle_error_at_line(line_number, "can't pchar, value out of range\n");

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - Checks if the integer is an alphabetic character
 * @c: Integer to be checked
 * Return: 1 if it's an alphabetic character, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

