#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*Error hanlding*/
void error(int error_code, ...);
void error2(int error_code, ...);  
void string_error(int error_code, ...);
void rotr(stack_t **, unsigned int);


/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void stackPrint(stack_t **, unsigned int);
void addStack(stack_t **, unsigned int);
void queueAdd(stack_t **, unsigned int);

void funcCal(op_func, char *, char *, int, int);

void topStack(stack_t **, unsigned int);
void popStack(stack_t **, unsigned int);
void stackNop(stack_t **, unsigned int);
void stackSwap(stack_t **, unsigned int);

/*Math operations with nodes*/
void nodesAdd(stack_t **, unsigned int);
void nodesSub(stack_t **, unsigned int);
void nodesDiv(stack_t **, unsigned int);
void nodesMult(stack_t **, unsigned int);
void nodesMod(stack_t **, unsigned int);

/*String operations*/
void printAscii(stack_t **, unsigned int);
void stringPrnt(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int separate(char *buffer, int line_number, int format);
void fileReader(FILE *);
int len_chars(FILE *);
void getFunc(char *, char *, int, int);

#endif
