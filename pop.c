#include "monty.h"

/**
 * monty_rotl - function that handles rotl
 * @stack: stack adress
 * @line_number: the number of a line
 *
 * Return: always zero success
 */


void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
/**
 * monty_rotr - handles rotr.
 * @stack: handles the stack adress
 * @line_number: the line number
 *
 * Return: zero success
 */

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
/**
 * monty_stack - handles the stack of the programme
 * @stack: the address of the stack
 * @line_number: line number of program where the stack is
 *
 * Return: sucess zero
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
 * monty_queue - handles th queue of the monty
 * @stack: address of the stack
 * @line_number: line number of the monty thats on the queue
 */

void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

