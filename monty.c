#include "main.h"
int main(int argc, char **argv)
{
    FILE *file_handle;
    /*char buffer[5];*/
    char command_name[5];
    stack_t *stack = NULL;
    /*int command_parametre;*/
    /*char *line = NULL, **clean_commands = NULL, buffer[100]*/
    unsigned int line_number = 0;
    /*int read;*/
    /*stack_t *stack = NULL;*/
    
    if (argc != 2) 
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file_handle = fopen(argv[1], "r");
    if (!file_handle)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /*reading the file*/
    while (fscanf(file_handle, "%4s", command_name) == 1)
    {
        line_number++;
        /*command_name[4] = '\0';*/
        /*printf("line number = %d\n", line_number);*/
        execute_command(command_name, line_number, file_handle, &stack);
        /*print_stack_from_top(stack);*/
        /*printf("got out from exec\n");*/
        /*command_name[0] = '\0';*/
        
        /*printf("finished while \n");*/
    }
    fclose(file_handle);
    free_stackt(&stack);
    return(0);
}
