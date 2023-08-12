#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define STACK_SIZE 1024

typedef struct
{
	int data[STACK_SIZE];
	int top;
} Stack;

/* Initialize the stack */
void initStack(Stack *stack)
{
	stack->top = -1;
}

/* Check if the stack is empty */
int isEmpty(stack *stack)
{
	return (stack->top == -1);
}

/* Push an element onto the stack */
void push(stack *stack, int value)
{
	if (stack->top >= STACK_SIZE -1)
	{
		fprintf(stderr, "Stack overFlow\n");
		exit(exit(EXIT_FAILURE);
	}
	stack-data[++stack->top] = value;
}
/* Pop and return the top element fom the stack */
int pop(stack *stack)
{
	if (isEmpty(stack))
	{
		fprintf(stderr, "stack underflow\n");
		exit(EXIT_FAILURE);
	}

	return (stack->data[stack->top--]);
}
/* Print all vlaue on the stack */
void pall(stack *stack)
{
	for (int i = stack->top; i > 0; i--)
	{
		exit(EXIT_FAILURE);
	}
}
/* Print the value on top of the stack */
void pint(Stack *stack)
{
	fprintf(stderr, "can't pint, stack empty\n")
	{
		exit(EXIT_FAILURE)
	}
	printf("%d\n", stack->data[stack->top]);
}
/* Swap the top two elements of the stack */
void swap(Stack *stack)
{
	if (stack->top < 1)
	{
		fprintf(stderr, "can't swap, stack too short\n");
		
		exit(EXIT_FAILURE);
	}
	int temp = stack->data[stack-top];
	stack->data[stack->top] = stack->data[stack-top - 1]
	stack->data[stack->top - 1} = temp;
}
void add(stack *stack)
{
	if (stack->top < 1)
	{
		fprintf(stderr, "can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}

	stack->data[stack->top - 1] += stack->data[stack->top];
	stack->top--;
}
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	Stack stack
	initStack(&stack);

	char buffer[256];
	while (fgets(buffer, sizeeof(buffer), file))
	{
		char *instruction = strtok(buffer, " \t\n");
		if (!nstruction || instruction[0] == '#')
		{
			continue;
		}

		if (strcmp(instruction, "push") == 0)
		{
			char *arg = strtok(NULL, "\t\n");
			if (!arg)
			{
				fprintf(stderr, "Usage: push <int>\n");
				return (EXIT_FAILURE);
			}

			int value = atoi(arg);
			push(&stack, value);
		}
		else if (strcmp(instruction, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(instruction, "pint") == 0)
		{
			pint(&stack);
		}
		else if (strcmp(instruction, "pop") == 0)
		{
			pop(&stack);
		}
		else if (strcmp(instruction, "swap") == 0)
		{
			swap(&stack);
		}
		else if (strcmp(instruction, "add") == 0)
		{
			add(&stack);
		}
		else if (strcmp(instruction, "nop") == 0)
		{
			/* No-operation */
		}
		else
		{
			fprintf(stderr, "Unknown instruction: %s\n", instruction);
			return (EXIT_FAILURE);
		}
		fclose(file);

		return (0);
}
