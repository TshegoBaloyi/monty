#include "monty.h"

int handle_pop_error(unsigned int line_number);
int handle_pint_error(unsigned int line_number);
int handle_short_stack_error(unsigned int line_number, char *operation);
int handle_div_error(unsigned int line_number);
int handle_pchar_error(unsigned int line_number, char *error_message);
/**
 * handle_pop_error - it handles pop error
 * @line_number: the line number
 *
 * Return: always Exit failure success
 */

int handle_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L %u: empty stack for pop\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * handle_pint_error - handles pint error
 * @line_number: handles number of the line
 *
 * Return: exit failure sucess
 */

int handle_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u:stack is empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * handle_short_stack_error - handle short stack error
 * @line_number: the line number
 * @operation: operation address
 *
 * Return: success exit failure
 */

int handle_short_stack_error(unsigned int line_number, char *operation)
{
	fprintf(stderr, "L%u: can't%s, short stack\n", line_number, operation);
	return (EXIT_FAILURE);
}

/**
 * handle_div_error - handles div error
 * @line_number: line number
 *
 * Return: success exit failure
 */

int handle_div_error(unsigned int line_number)
{
	fprintf(stderr, "Error at line %u: Division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * handle_pchar_error - handle putchar error
 * @line_number:  line number
 * @error_message:  display error message
 *
 * Return: exit failure sucess
 */

int handle_pchar_error(unsigned int line_number, char *error_message)
{
	fprintf(stderr, "L%u: cannot  pchar, %s\n", line_number, error_message);
	return (EXIT_FAILURE);
}

/**
 * main - main code
 *
 * Return: zero sucess
 */

int main(void)
{
	return (0);
}
