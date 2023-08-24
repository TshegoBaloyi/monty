#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
}

void monty_pchar(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL) {
        set_op_tok_error(handle_pchar_error(line_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127) {
        set_op_tok_error(handle_pchar_error(line_number, "value out of range"));
        return;
    }

    putchar((*stack)->next->n);
    putchar('\n');
}

void monty_pstr(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127)) {
        putchar(tmp->n);
        tmp = tmp->next;
    }

    putchar('\n');
    (void)line_number;
}

