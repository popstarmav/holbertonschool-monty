#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Data Structures */

struct stack_s; /* Forward declaration */

typedef void (*instruct_func)(struct stack_s **stack, unsigned int line_number);

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous node in the stack
 * @next: Pointer to the next node in the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Struct for opcode and function pointer
 * @opcode: The opcode (e.g., "push")
 * @f: Pointer to the function that handles the opcode
 */
typedef struct instruction_s
{
    char *opcode;
    instruct_func f;
} instruction_t;

/* Global Variables */

extern struct global_vars
{
    FILE *file;
    char *buffer;
    int push_arg;
} var_global;

/* Function Prototypes */
instruct_func get_op_func(char *str);

/* monty_main.c */
void read_file(char *filename, struct stack_s **stack);

/* monty_execute.c */
void execute_opcode(char *opcode, struct stack_s **stack, unsigned int line_number);

/* monty_opcodes.c */
void _push(struct stack_s **stack, unsigned int line_number);
void _pall(struct stack_s **stack, unsigned int line_number);
void _pint(struct stack_s **stack, unsigned int line_number);
void _pop(struct stack_s **stack, unsigned int line_number);
void _swap(struct stack_s **stack, unsigned int line_number);
void _add(struct stack_s **stack, unsigned int line_number);
void _nop(struct stack_s **stack, unsigned int line_number);
void _sub(struct stack_s **stack, unsigned int line_number);
void _mul(struct stack_s **stack, unsigned int line_number);
void _div(struct stack_s **stack, unsigned int line_number);
void _mod(struct stack_s **stack, unsigned int line_number);
void _pchar(struct stack_s **stack, unsigned int line_number);
void _pstr(struct stack_s **stack, unsigned int line_number);
void _rotl(struct stack_s **stack, unsigned int line_number);
void _rotr(struct stack_s **stack, unsigned int line_number);
int _isalpha(int c);

/* monty_utility.c */
void handle_error(const char *msg);
void handle_error_at_line(unsigned int line_number, const char *msg);
int isnumber(char *str);

/* Freeing and Cleanup */
void free_dlistint(struct stack_s *head);

/* Additional Functions */
char *parse_line(char *line, struct stack_s **stack, unsigned int line_number);

#endif /* MONTY_H */
