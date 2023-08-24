#include "monty.h"  

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void custom_monty_push(stack_t **custom_stack, unsigned int custom_line_number)
{
    stack_t *tmp, *new_item;
    int i;

    new_item = malloc(sizeof(stack_t));
    if (new_item == NULL)
    {
        set_op_tok_error(handleMallocError());
        return;
    }

    if (op_toks[1] == NULL)
    {
        set_op_tok_error(handle_pint_error(custom_line_number));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            set_op_tok_error(handleNoIntegerError(custom_line_number));
            return;
        }
    }
    new_item->n = atoi(op_toks[1]);

    if (check_mode(*custom_stack) == STACK) /* STACK mode insert at front */
    {
        tmp = (*custom_stack)->next;
        new_item->prev = *custom_stack;
        new_item->next = tmp;
        if (tmp)
            tmp->prev = new_item;
        (*custom_stack)->next = new_item;
    }
    else /* QUEUE mode insert at end */
    {
        tmp = *custom_stack;
        while (tmp->next)
            tmp = tmp->next;
        new_item->prev = tmp;
        new_item->next = NULL;
        tmp->next = new_item;
    }
}

/**
 * custom_monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void custom_monty_pall(stack_t **custom_stack, unsigned int custom_line_number)
{
    stack_t *tmp = (*custom_stack)->next;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)custom_line_number;
}

/**
 * custom_monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void custom_monty_pint(stack_t **custom_stack, unsigned int custom_line_number)
{
    if ((*custom_stack)->next == NULL)
    {
        set_op_tok_error(handle_pint_error(custom_line_number));
        return;
    }
    printf("%d\n", (*custom_stack)->next->n);
}

/**
 * custom_monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void custom_monty_pop(stack_t **custom_stack, unsigned int custom_line_number)
{
    stack_t *next_item = NULL;

    if ((*custom_stack)->next == NULL)
    {
        set_op_tok_error(handle_pop_error(custom_line_number));
        return;
    }

    next_item = (*custom_stack)->next->next;
    free((*custom_stack)->next);
    if (next_item)
        next_item->prev = *custom_stack;
    (*custom_stack)->next = next_item;
}

/**
 * custom_monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void custom_monty_swap(stack_t **custom_stack, unsigned int custom_line_number)
{
    stack_t *tmp;

    if ((*custom_stack)->next == NULL || (*custom_stack)->next->next == NULL)
    {
        set_op_tok_error(handle_short_stack_error(custom_line_number, "swap"));
        return;
    }

    tmp = (*custom_stack)->next->next;
    (*custom_stack)->next->next = tmp->next;
    (*custom_stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*custom_stack)->next;
    tmp->next = (*custom_stack)->next;
    tmp->prev = *custom_stack;
    (*custom_stack)->next = tmp;
}

