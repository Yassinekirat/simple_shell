#include "main.h"

/**
* tokenize_command - tokenize the user input
*
* @input_line: the input string
*
* Return: Returns the line tokenized
*/

char **tokenize_command(char *input_line)
{
	char *delimiter = " \t\n";

	char *line_copy = strdup(input_line);

	char **tokens = NULL;

	size_t token_count = 0;

	if (input_line == NULL)
		return (NULL);

	token_count = count_tokens(line_copy, delimiter);
	if (token_count == 0)
	{
		free(input_line);
		free(line_copy);
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * (token_count + 1));
	if (tokens == NULL)
	{
		free(line_copy);
		return (NULL);
	}

	populate_tokens(tokens, input_line, delimiter);

	free(line_copy);

	return (tokens);
}
