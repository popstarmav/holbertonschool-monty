#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *stack)
{
	stack->top = NULL;
}

int isEmpty(stack *stack)
{
	return (stack->top == NULL);
}

void push(Stack *stack, int data)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));

	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		fprintf(stderr, "Stack underflow.\n");
		exit(1);
	}

	int data = stack->top->data
	StackNode* temp = stack->top;
	stack->top = stack->top-next;
	free(temp);
	return (data);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);

		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error opening file: %s\n", argv[1]);

		return (EXIT_FAILURE):
	}

	Stack stack;
	initStack(&stack);

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file))
	{
		char **instruction = strtok(buffer, " \t\n");
		if (!instruction || instruction[0] == '#')
		{
			continue;
		}

		if (strcmp(instruction, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");

			if (!arg)
			{
				fprintf(stderr, "Usage: push <int>\n");
				return(EXIT_FAILURE);
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
			pop(&stack)
		}
		else if (strcmp(instruction, "swap") == 0)
		{
			swap(&stack);
		}
		else if (strcmp(instruction, "add") == 0)
		{
			add(&stack);
		}
		else if (strcmp(instruction, "nope") == 0)
		{
			/* No-operation */
		}
		fprintf(stderr, "Unknown instruction: %s\n", instruction);
		return (EXIT_FAILURE);
	}

	fclose(file);

	return (0);
}


