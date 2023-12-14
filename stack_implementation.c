#include "main.h"
void pall_function(stack_t **stack,unsigned int line_number) {
    int integer_to_add = global_var;
    (void)stack;
    (void)line_number;
    printf("_n from pall = %d\n", integer_to_add);
}
void free_stackt(stack_t **stack)
{
    stack_t *current = NULL;

    if(!(*stack))
    {
        printf("nothing to free");
        return;
    }
    while(*stack)
    {
        current = (*stack)->prev;
        free(*stack);
        *stack = current;
    }
    return;
}
void push_function_empty_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *top = NULL;
    (void)line_number;

    if (*stack)
    {
        printf("push_function_empty_stack : i should not be called");
    }
    top = malloc(sizeof(stack_t));
    if (!top)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    top->n = global_var;
    top->next = NULL;
    top->prev = NULL;
    *stack = top;
    return;
}
void push_func_no_empty_stack(stack_t **stack,unsigned int line_number)
{
    stack_t *new_top = NULL, *old_top = NULL;
    (void)line_number;
    if (!(*stack))
    {
        fprintf(stderr, "push_func_no_empty_stack : i should not be called");
        return;
    }
    new_top = malloc(sizeof(stack_t));
    if (!new_top)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    old_top = *stack;
    new_top->n = global_var;
    new_top->prev = old_top;
    new_top->next = NULL;
    *stack = new_top;
    /*
    new_top->next = NULL;
    new_top->prev = (*stack);
    new_top->n = global_var;
    */
}
void push_function(stack_t **stack,unsigned int line_number) {
    int integer_to_add = global_var;
    if (!(*stack))
    {
        push_function_empty_stack(stack, line_number);
        return;
    }
    push_func_no_empty_stack(stack, line_number);
    return;
}
