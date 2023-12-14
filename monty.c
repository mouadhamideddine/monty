#include "main.h"
void print_stack(stack_t *stack)
{
    if (!stack)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");

    while (stack)
    {
        printf("%d ", stack->n);
        stack = stack->prev;
    }

    printf("\n");
}
int _getline(char ** line, FILE * fp)
{

    int bufflen = 80;
    char * buff;
    char * tempbuff;
    int i = 0;
    char c;

    if(*line != NULL) return -1;
    buff = malloc(bufflen * sizeof(char));
    while(1)
    {
        if(i == bufflen - 1)
        {
            tempbuff = malloc(2 * bufflen * sizeof(char));
            strncpy(tempbuff, buff, bufflen);
            free(buff);
            buff = tempbuff;
            tempbuff = NULL;
            bufflen = bufflen * 2;
        }
        c = fgetc(fp);
        if(c == '\n' || c == EOF)
        {
            buff[i] = '\0';
            break;
        }
        else if(c == '\b' && i > 0) i = i - 2;
        else buff[i] = c;
        i++;
    }

    *line = malloc((i + 1) * sizeof(char));
    strncpy(*line, buff, i + 1);
    free(buff);
    return i;
}


/*
void print2darray(char *array[]) 
{
    // Iterate through the array until a NULL pointer is encountered
    for (int i = 0; array[i] != NULL; ++i) {
        //printf("%s<- this is a space\n",array[i]);
    }
}
* main - MONTY PROGRAM
* @argc : argument count
* @argv : argument vector
* Return: -1 if error 1 if success
**/
int main(int argc, char **argv)
{
    FILE *file_handle;
    char *line = NULL, **clean_commands = NULL;
    unsigned int line_number = 0;
    int read;
    stack_t *stack = NULL;
    
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
    while ((read = _getline(&line,file_handle)) != -1)
    {
        line_number++;
        clean_commands = tokenizeline(line);
        if (check_command(clean_commands) == -1)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, clean_commands[0]);
            free_array(clean_commands);
            free(line);
            fclose(file_handle);
            exit(EXIT_FAILURE);
        }
        execute_command(clean_commands, line_number, &stack);

        free_array(clean_commands);
    }
    print_stack(stack);
    free(line);
    free_stackt(&stack);
    fclose(file_handle);
    return (0);
}


