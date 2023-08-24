#include "monty.h"

int handleUsageError(void);
int handleUnknownOperationError(char *operation, unsigned int lineNumber);
int handleFileOpenError(char *filename);
int handleMallocError(void);
int handleNoIntegerError(unsigned int lineNumber);

int handleUsageError(void)
{
    fprintf(stderr, "USAGE: program_name file\n");
    return (EXIT_FAILURE);
}


int handleUnknownOperationError(char *operation, unsigned int lineNumber)
{
    fprintf(stderr, "Line %u: unknown operation '%s'\n", lineNumber, operation);
    return (EXIT_FAILURE);
}

int handleFileOpenError(char *filename)
{
    fprintf(stderr, "Error: Unable to open file %s\n", filename);
    return (EXIT_FAILURE);
}

int handleMallocError(void)
{
    fprintf(stderr, "Error: memory allocation failed\n");
    return (EXIT_FAILURE);
}


int handleNoIntegerError(unsigned int lineNumber)
{
    fprintf(stderr, "Line %u: usage: push integer\n", lineNumber);
    return (EXIT_FAILURE);
}

