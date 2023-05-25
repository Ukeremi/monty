#include "monty.h"
/**
 * uf_push - push int to the  stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs
 */
void uf_push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * uf_pall - print all the function
 * @stack: pointer to linked list stack
 * @line_number: number opcode
 */
void uf_pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runa;

	runa = *stack;
	while (runa != NULL)
	{
		printf("%d\n", runa->n);
		runa = runa->next;
	}
}

/**
 * uf_pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void uf_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runa;

	runa = *stack;
	if (runa == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runa->n);
}

/**
 * uf_pop - remove element from the list
 *@stack: pointer to the first node
 *@line_number: integer
 *Return: void
 */
void uf_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free the list
 * @head: pointer to the first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
