#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void initStack(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
void pall(Stack *stack);
void pint(Stack *stack);
void swap(Stack *stack);
void add(Stack *stack);

#endif /* MONTY_H */

