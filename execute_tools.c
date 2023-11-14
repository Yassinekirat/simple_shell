#include "main.h"

/**
 * find_command_path - find the full path.
 *
 * @command: the command and its arguments.
 * @shell_name: name of the shell.
 * @line_number: An integer representing line number.
 *
 * Return: the full path.
 */

char *find_command_path(char *command, char **shell_name, int line_number)
{
	char *full_path = get_full_command_path(command);

	if (!full_path)
	{
		print_error(shell_name[0], command, line_number);
		return (NULL);
	}
	return (full_path);
}

/**
 * execute_command - execute commands
 *
 * @command: the command and its arguments.
 * @full_path: The full path
 *
 * Return: the exit status of the executed command.
 */

int execute_command(char *full_path, char **command)
{
	if (execve(full_path, command, environ) == -1)
	{
		perror("execve");
		write(STDERR_FILENO, "Error in execve: ", 17);
		write(STDERR_FILENO, full_path, strlen(full_path));
		write(STDERR_FILENO, "\n", 1);
		free(full_path);
		freearr(command);
		_exit(EXIT_FAILURE);
	}

	return (0);
}
