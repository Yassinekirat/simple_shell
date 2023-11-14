#include "main.h"

/**
* main - Shell command starting infinit loop
*
* @argc: Argument count
* @argv: Argument values (including the shell name)
*
* Return: Exit status
*/
int main(int argc, char **argv)
{
	char **command = NULL, **environment = environ, *input_line = NULL;

	int status = 0, line_number = 0;

	(void) argc;

	while (1)
	{
		input_line = read_and_increment(&status, &line_number);
		if (input_line == NULL)
		{
			return (status);
		}
		command = tokenize_command(input_line);
		if (command == NULL)
			continue;
		if (strcmp(command[0], "exit") == 0)
		{
			freearr(command);
			exit(status);
		}
		if (command && strcmp(command[0], "env") == 0)
		{
			if (environ == NULL || *environ == NULL)
				write(STDOUT_FILENO, "env: command not found\n", 23);
			else
			{
				while (*environment != NULL)
				{
					write(STDOUT_FILENO, *environment, strlen(*environment));
					write(STDOUT_FILENO, "\n", 1);
					environment++;
				}
			}
			freearr(command);
			continue;
		}
		status = _execute(command, argv, line_number);
	}
}
