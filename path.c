#include "main.h"

/**
*  get_full_command_path - Builds and validates command path
*
* @command: the command and its arguments.
*
* Return: null
*/
char *get_full_command_path(char *command)
{
	char *path_env, *full_cmd, *dir;

	struct stat st;

	full_cmd = check_absolute_path(command);
	if (full_cmd != NULL)
	{
		return (full_cmd);
	}

	path_env = _getenv("PATH");
	path_env = check_empty_path(path_env);
	if (!path_env)
	{
		return (NULL);
	}
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = _construct_full_cmd(dir, command);
		if (full_cmd != NULL)
		{
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
		}

		dir = strtok(NULL, ":");
	}

	free(path_env);
	return (NULL);
}
