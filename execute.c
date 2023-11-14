#include "main.h"

/**
 * _execute - execute a command with arguments
 *
 * @command: array of command and arguments
 * @av: array of program arguments
 * @command_index: command index
 *
 * Return: Returns the exit status of the executed command
 */
int _execute(char **command, char **av, int command_index)
{
	pid_t child_pid;
	int child_status;

	char *full_cmd_path;

	full_cmd_path = find_command_path(command[0], av, command_index);
	if (!full_cmd_path)
	{
		freearr(command);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		execute_command(full_cmd_path, command);
	}
	else
	{
		waitpid(child_pid, &child_status, 0);

		if (child_status == -1)
		{
			perror("waitpid");
			freearr(command);
			free(full_cmd_path);
			return (127);
		}

		freearr(command);
		free(full_cmd_path);
	}

	return (WEXITSTATUS(child_status));
}
