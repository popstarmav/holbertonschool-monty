#include "monty.h"
#include <ctype.h>
#include "helper.h"

/* Print the value at the top of the stack, followed by a newline */
void pint(stack_t *stack, unsigned int line_number) {
    if (!stack) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

/* Print all values on the stack, starting from the top */
void pall(stack_t *stack) {
    stack_t *current = stack;
    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/* Process Monty instructions */
void process_opcode(stack_t **stack, char *opcode, char *arg, unsigned int line_number) {
    if (strcmp(opcode, "push") == 0) {
        if (!arg || !is_numeric(arg)) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(arg);
        push(stack, value);
    } else if (strcmp(opcode, "pint") == 0) {
        pint(*stack, line_number);
    } else if (strcmp(opcode, "pall") == 0) {
        pall(*stack);
    } else if (strcmp(opcode, "pop") == 0) {
        pop(stack, line_number);
    } else if (strcmp(opcode, "swap") == 0) {
        swap(stack, line_number);
    } else if (strcmp(opcode, "add") == 0) {
        add(stack, line_number);
    } else {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

/* Helper function to check if a string is numeric */
int is_numeric(const char *str) {
    if (!str)
        return 0;

    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}
