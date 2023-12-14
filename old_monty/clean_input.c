#include "main.h"
int containsNonWhitespace(const char str[])
{
    int index = 0;

    while (str[index] != '\0')
	{
		if (!isspace(str[index]))
		{
			return 1;
			index++;
		}
	}
	return 0;
}
char *_strdup(char *str)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = strlen(str) + 1;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		return (NULL);
	}

	strcpy(dupl, str);
	return (dupl);
}
/**
 * tokenizeline -  delimiters
 * @input: string
 * Return: strings
 */
char **tokenizeline(char *input)
{
	char **tokenized_input = NULL;
	char delimiters[] = {' ', '\t', '\n', '\0'};
	char *str_copy = NULL;
	char *token = NULL;
	int count_token = 0;
	int i = 0;

	if (input == NULL)
	{
		return (NULL);
	}
	if (containsNonWhitespace(input) == 0)
	{
		return (NULL);
	}
	str_copy = _strdup(input);
	token = strtok(str_copy, delimiters);
	while (token != NULL)
	{
		count_token++;
		token = strtok(NULL, delimiters);
	}
	free(str_copy);
	str_copy = NULL;
	tokenized_input = malloc(sizeof(char *) * (count_token + 1));
	if (tokenized_input == NULL)
	{
		free(input);
		return (NULL);
	}
	token = strtok(input, delimiters);
	while (token != NULL)
	{
		tokenized_input[i] = _strdup(token);
		token = strtok(NULL, delimiters);
		i++;
	}
	tokenized_input[i] = NULL;
	return (tokenized_input);
}

int free_array(char **array)
{
	int i = 0;

	if (array == NULL)
	{
		return (0);
	}

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return (0);
}
int check_command(char **tokenized_line)
{
	char *commands[] = {"push", "pall", NULL};
	int index = 0;
	
	if (!tokenized_line || tokenized_line[0] == NULL)
	{
		return(0); /*no check = success*/
	}
	while(commands[index])
	{
		if (strcmp(tokenized_line[0], commands[index]) == 0)
		{
			return (0); /*command exists*/
		}
		index++;
	}
	return (-1); /*no compatible command*/
}
