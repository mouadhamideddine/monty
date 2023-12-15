#include "monty.h"
int parametre_funcs();
int no_parametre_funcs();
int requires_parametre(char *command, FILE *filehandle)
{
    char *two_parametres[] = {"push", NULL};
    int index = 0;
    int parametre;

    /*printf("about to enter requiremes parametre loop \n");*/
    while(two_parametres[index] != NULL)
    {
        /*printf("entered while loop in requires parametres \n");*/
        if(strcmp(two_parametres[index], command) == 0)
        {
            /*printf("requires_parametres says found match \n");*/
            fscanf(filehandle, "%d", &parametre);
            global_var = parametre;
            return(0);
        }
        index++;
    }
    return(-1);
}
int execute_command(char *command, unsigned int linenumber, FILE *filehandle, stack_t **stack)
{
    int index = 0;
    int c;
    char nop[] = "nop";
    instruction_t instructions[] = 
    {
        {"push", push_function},
        {"pall", pall_function},
        {"pint", pint_function},
        {"pop", pop_function},
        {"add", add_function},
        {NULL, NULL},
    };
    /*printf("entered exec_commnad\n");*/
    if (strcmp(command, nop) == 0)
    {
        while ((c = fgetc(filehandle)) != '\n' && c != EOF);
        return (0);
    }
    while (instructions[index].opcode)
    {
        /*printf("looping\n");*/
        if (strcmp(instructions[index].opcode, command) == 0)
        {
            /*printf("found match function \n");*/
            requires_parametre(command, filehandle);
            /*printf("got out from requires parametre \n");*/
            instructions[index].f(stack, linenumber);
            while ((c = fgetc(filehandle)) != '\n' && c != EOF);
            /*fscanf(filehandle, "\n");*/
            /*printf("about to get out from exec command \n");*/
            return(0);
        }
        index++;
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", linenumber, command);
    exit(EXIT_FAILURE);
    fclose(filehandle);
}