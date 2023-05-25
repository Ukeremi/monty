#include "monty.h"

/**
 * uf_pstr - print string from the top
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void uf_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || is_alpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * uf_rotl - This will rotate the stack to the left
 * @stack: pointer to the head
 * @line_number: number of line opcode occurs on
 */
void uf_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runa = *stack;


	int ukp1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	ukp1 = runa->n;

	while (runa->next)
	{
		runa = runa->next;
		runa->prev->n = runa->n;
	}

	runa->n = ukp1;
}

/**
 * uf_rotr - It rotates the first two values in the stack
 * @stack: pointer to the head
 * @line_number: number of line opcode occurs on
 */
void uf_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runa = *stack;

	int ukp1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runa->next)
		runa = runa->next;

	ukp1 = runa->n;

	while (runa->prev)
	{
		runa = runa->prev;
		runa->next->n = runa->n;
	}

	runa->n = ukp1;
}
