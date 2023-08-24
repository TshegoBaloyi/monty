#include "monty.h"

int handle_pop_error(unsigned int line_number);
int handle_pint_error(unsigned int line_number);
int handle_short_stack_error(unsigned int line_number, char *operation);
int handle_div_error(unsigned int line_number);
int handle_pchar_error(unsigned int line_number, char *error_message);

int handle_pop_error(unsigned int line_number) {
    fprintf(stderr, "Error at line %u: Cannot perform pop operation on an empty stack\n", line_number);
    return (EXIT_FAILURE);
}

int handle_pint_error(unsigned int line_number) {
    fprintf(stderr, "Error at line %u: Unable to pint, the stack is empty\n", line_number);
    return (EXIT_FAILURE);
}

int handle_short_stack_error(unsigned int line_number, char *operation) {
    fprintf(stderr, "Error at line %u: Unable to perform %s, the stack has insufficient elements\n", line_number, operation);
    return (EXIT_FAILURE);
}

int handle_div_error(unsigned int line_number) {
    fprintf(stderr, "Error at line %u: Division by zero\n", line_number);
    return (EXIT_FAILURE);
}

int handle_pchar_error(unsigned int line_number, char *error_message) {
    fprintf(stderr, "Error at line %u: Unable to pchar, %s\n", line_number, error_message);
    return (EXIT_FAILURE);
}

int main() {
  
    return 0;
}

