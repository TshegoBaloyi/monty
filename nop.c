#include "monty.h"

/**
 * monty_nop- handles the nop of the programm
 * @stack: allocates the memory of stack
 * @line_number: displays the line number
 *
 * Return: zero sucess
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - the putchar of the project
 * @stack: the stack address
 * @line_number: the number of the line
 *
 * Return: zero success
 */

void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
	set_op_tok_error(handle_pchar_error(line_number, "stack empty"));
	return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
	set_op_tok_error(handle_pchar_error(line_number, "value out of range"));
	return;
	}

	putchar((*stack)->next->n);
	putchar('\n');
}

/**
 * monty_pstr- handles the  program pstr
 * @stack: the stak address
 * @line_number: the line number
 *
 * Return : always zero sucess
 */

void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
	putchar(tmp->n);
	tmp = tmp->next;
	}

	putchar('\n');
	(void)line_number;
}
