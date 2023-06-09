#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*-- Struct Definitions --*/
extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @_buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *_buffer;
} global_var;

extern global_var var_global;

void nread_file(char *filename, stack_t **stack);
char *_parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func getopcode_func(char *str);

/*-- Given  Monty function Names --*/
void uf_push(stack_t **stack, unsigned int line_number);
void uf_pall(stack_t **stack, unsigned int line_number);
void uf_pint(stack_t **stack, unsigned int line_number);
void uf_pop(stack_t **stack, unsigned int line_number);
void uf_swap(stack_t **stack, unsigned int line_number);
void uf_nop(stack_t **stack, unsigned int line_number);
void uf_rotl(stack_t **stack, unsigned int line_number);
void uf_rotr(stack_t **stack, unsigned int line_number);

/*Functions string ascci */
void uf_pchar(stack_t **stack, unsigned int line_number);
void uf_pstr(stack_t **stack, unsigned int line_number);

/*Functions math*/
void uf_sub(stack_t **stack, unsigned int line_number);
void uf_add(stack_t **stack, unsigned int line_number);
void uf_mul(stack_t **stack, unsigned int line_number);
void uf_div(stack_t **stack, unsigned int line_number);
void uf_mod(stack_t **stack, unsigned int line_number);

/*-- All the Utility functions --*/
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int is_alpha(int c);

#endif /* endif */
