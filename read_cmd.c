#include "main.h"

/**
* read_line - read a line of input from stdin
*
* Return: Returns the input line as a string
*/

char *read_line(void)
{
	char *input_line = NULL;

	size_t line_length = 0;
	ssize_t read_status;

	display_prompt();
	read_status = getline(&input_line, &line_length, stdin);

	if (read_status == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			putchar('\n');
		}
		free(input_line);
		input_line = NULL;
		return (NULL);
	}

	return (input_line);
}

/**
* read_and_increment - Read a line of input and increment line number
*
* @status: Current exit status
* @line_number: Current line number
*
* Return: The input line
*/
char *read_and_increment(int *status, int *line_number)
{
	char *input_line = read_line();

	if (input_line == NULL)
	{
		*status = *status;
		return (NULL);
	}

	(*line_number)++;
	return (input_line);
}
