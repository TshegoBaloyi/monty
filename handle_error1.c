#include "monty.h"

int handleUsageError(void);
int handleUnknownOperationError(char *operation, unsigned int lineNumber);
int handleFileOpenError(char *filename);
int handleMallocError(void);
int handleNoIntegerError(unsigned int lineNumber);

/**
 * handleUsageError- it handles error
 *
 * Return: EXIT Failure success
 */

int handleUsageError(void)
{
	fprintf(stderr, "USAGE: program_name file\n");
	return (EXIT_FAILURE);
}

/**
 * handleUnknownOperationError - it handles operation error that is unknown
 * @operation: adress operation
 * @lineNumber: the number of the line
 *
 * Return: success Exit Failure
 */

int handleUnknownOperationError(char *operation, unsigned int lineNumber)
{
	fprintf(stderr, "Line %u: unknown operation '%s'\n", lineNumber, operation);
	return (EXIT_FAILURE);
}

/**
 * handleFileOpenError - it handles open file error
 * @filename: the name of the file
 * Return: exit failure sucess
 */

int handleFileOpenError(char *filename)
{
	fprintf(stderr, "Error: Unable to open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * handleMallocError - it handles malloc error
 *
 * Return: sucess return failure
 */

int handleMallocError(void)
{
	fprintf(stderr, "Error: memory allocation failed\n");
	return (EXIT_FAILURE);
}

/**
 * handleNoIntegerError - it handles error of no interger
 * @lineNumber: the line number
 *  Return: always success exit failure
 */

int handleNoIntegerError(unsigned int lineNumber)
{
	fprintf(stderr, "Line %u: usage: push integer\n", lineNumber);
	return (EXIT_FAILURE);
}

