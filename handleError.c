#include "monty.h"

/**
 * string_error - handles errors.
 * @error_code: The error codes are the following:
 * (1) ~> The number inside a node is outside ASCII bounds.
 * (2) ~> The stack is empty.
 */
void string_error(int error_code, ...)
{
	va_list bc;
	int l_num;

	va_start(bc, error_code);
	l_num = va_arg(bc, int);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 2:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * error2 - handles errors.
 * @error_code: The error codes are the following:
 * (3) => When the stack it empty for pint.
 * (4) => When the stack it empty for pop.
 * (5) => When stack is too short for operation.
 * (6) => Division by zero.
 */
void error2(int error_code, ...)
{
	va_list bc;
	char *op;
	int l_num;

	va_start(bc, error_code);
	switch (error_code)
	{
		case 3:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(bc, int));
			break;
		case 4:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(bc, int));
			break;
		case 5:
			l_num = va_arg(bc, unsigned int);
			op = va_arg(bc, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 6:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(bc, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * error - handles error code messages.
 * @error_code: The error codes are the following:
 * (7) => The user does not give any file or more than one file to the program.
 * (8) => The file provided is not a file that can be opened or read.
 * (9) => The file provided contains an invalid instruction.
 * (10) => When the program is unable to malloc more memory.
 * (11) => When the parameter passed to the instruction "push" is not an int.
 * (12) => When the stack it empty for pint.
 * (13) => When the stack it empty for pop.
 * (14) => When stack is too short for operation.
 */
void error(int error_code, ...)
{
	va_list bc;
	char *op;
	int l_num;

	va_start(bc, error_code);
	switch (error_code)
	{
		case 7:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 8:
			fprintf(stderr, "Error: file can't open %s\n",
				va_arg(bc, char *));
			break;
		case 9:
			l_num = va_arg(bc, int);
			op = va_arg(bc, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 10:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 11:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(bc, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
