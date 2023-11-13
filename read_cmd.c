#include "main.h"

/**
 * read_line - read the user input
 *
 * Return: Returns the line of text read from the standard input
 */

char *read_line(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t n;

	display_prompt();
	n = getline(&line, &len, stdin);

	if (n == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			putchar('\n');
		}
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}
