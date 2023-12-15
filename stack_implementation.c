#include "monty.h"
void print_stack(stack_t *stack)
{
    if (!stack)
    {
        return;
    }
    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->prev;
    }
}
void pint_function(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL) 
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    } 
    else 
    {
        printf("%d\n", (*stack)->n);
    }
}
void add_function(stack_t **stack, unsigned int line_number)
{
    stack_t *top1 = NULL;
    stack_t *top2 = NULL;

    if (*stack == NULL || (*stack)->prev == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top1 = *stack;
    top2 = top1->prev;

    top2->n += top1->n;

    *stack = top2;
    if (top2->prev != NULL)
    {
        top2->prev = NULL;
    }

    free(top1);
}
void pop_function(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

   
    *stack = top->prev;

    if (*stack != NULL)
    {
        (*stack)->next = NULL;
    }

    free(top);
}
void print_stack_recursive(stack_t *stack)
{
    if (!stack)
        return;

    print_stack_recursive(stack->prev);
    printf("%d\n", stack->n);
}
void print_stack_from_top(stack_t *stack)
{
    if (!stack)
    {
        return;
    }
    print_stack_recursive(stack);
}
void pall_function(stack_t **stack,unsigned int line_number) 
{   
    (void)line_number;
    print_stack(*stack);
}
void free_stackt(stack_t **stack)
{
    stack_t *current = NULL;

    if(!(*stack))
    {
        /*printf("nothing to free");*/
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

    if (!(*stack))
    {
        push_function_empty_stack(stack, line_number);
        return;
    }
    push_func_no_empty_stack(stack, line_number);
    return;
}
