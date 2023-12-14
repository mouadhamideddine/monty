#include "main.h"
/*
func_for_command_2p - func_for_command_2parametre for exaple push 2
*/
int func_for_command_2p(char *_opcode, unsigned int _linenumber, stack_t **_stack)
{
    int index = 0;

    instruction_t instructions[] = {
        {"push", push_function},
        {"pall", pall_function},
        {NULL, NULL},
        };
    while (instructions[index].opcode)
    {
        if (strcmp(instructions[index].opcode, _opcode) == 0)
        {
            break;
        }
        index++;
    }
    instructions[index].f(_stack, _linenumber);
    return (0);
}
/*
execute_command - checks and gets command and call for execution
@tokenized_line : command and parametre
Return: -1 if fail 0 if success
*/
int is_only_digits(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
int execute_command(char **tokenized_line, unsigned int _linenumber, stack_t **_stack)
{
    int index = 0;

	if (!tokenized_line)
	{
		fprintf(stderr, "no commands\n");
		return (-1);
	}
    while(tokenized_line[index])
    {
        /*printf("from exec_command tokenized_line[%d] %s\n",index, tokenized_line[index]);*/
        index++;/*right length*/
    }
    /*
    if (index == 2)
    {
        if (is_only_digits(tokenized_line[1]) == 1) 
        {
            global_var = atoi(tokenized_line[1]);
            return (func_for_command_2p(tokenized_line[0], _linenumber, _stack));
        }
        fprintf(stderr, "L%u: unknown instruction %s %s\n", _linenumber, tokenized_line[0], tokenized_line[1]);
    }
    */
    global_var = atoi(tokenized_line[1]);
    return (func_for_command_2p(tokenized_line[0], _linenumber, _stack));
}
