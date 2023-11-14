#include "main.h"
#include <string.h>

/**
* count_tokens - count the tokens in the input string
*
* @input_line: the input string
* @delimiter: the delimiter characters
*
* Return: Returns the number of tokens
*/
size_t count_tokens(char *input_line, char *delimiter)
{
	size_t token_count = 0;
	char *token = strtok(input_line, delimiter);

	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delimiter);
	}

	return (token_count);
}

/**
* populate_tokens - populate array with tokens from the input
*
* @tokens: array of strings to populate
* @input_line: the input string
* @delimiter: the delimiter characters
*/
void populate_tokens(char **tokens, char *input_line, char *delimiter)
{
	int index = 0;

	char *token = strtok(input_line, delimiter);

	while (token != NULL)
	{
		tokens[index] = strdup(token);
		token = strtok(NULL, delimiter);
		index++;
	}

	tokens[index] = NULL;
	free(input_line);
}
