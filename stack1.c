#include "monty.h"

/**
 * _push - Push an integer onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode (unused)
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error("Error: malloc failed\n");

	new_node->n = var_global.push_arg;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * _pall - Print all elements in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode (unused)
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - Print the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		handle_error_at_line(line_number, "can't pint, stack empty\n");

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - Pop the top element off the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		handle_error_at_line(line_number, "can't pop an empty stack\n");

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * free_dlistint - Free a doubly linked list
 * @head: Pointer to the first node of the list
 */
void free_dlistint(stack_t *head)
{
	while (head)
	{
		stack_t *temp = head;
		head = head->next;
		free(temp);
	}
}

