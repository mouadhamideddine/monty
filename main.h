#ifndef MAIN_h
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
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
int global_var;
char **tokenizeline(char *input);
int free_array(char **array);
int check_command(char *tokenized_line[]);
void push_function(stack_t **stack,unsigned int line_number);
void pall_function(stack_t **stack,unsigned int line_number);
int execute_command(char **tokenized_line, unsigned int _linenumber, stack_t **_stack);
int func_for_command_2p(char *_opcode,unsigned int _linenumber, stack_t **_stack);
void free_stackt(stack_t **stack);
#endif