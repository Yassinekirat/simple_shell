#include "main.h"

/**
* _construct_full_cmd - Builds full path for command
*
* @dir: Path directory.
* @command: the command and its arguments.
*
* Return: Full command path
*/
char *_construct_full_cmd(char *dir, char *command)
{
	char *full_cmd = malloc(strlen(dir) + strlen(command) + 2);

	if (full_cmd)
	{
		strcpy(full_cmd, dir);
		strcat(full_cmd, "/");
		strcat(full_cmd, command);
	}
	return (full_cmd);
}

/**
* check_absolute_path - Check if command is absolute path
*
* @command: the command and its arguments.
*
* Return: null
*/
char *check_absolute_path(char *command)
{
	struct stat st;
	int i;

	for (i = 0; command[i] != '\0'; i++)

	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				return (strdup(command));
			}
			else
			{
				perror("stat");
			}

			return (NULL);
		}
	}

	return (NULL);
}

/**
* check_empty_path - Check and handle empty path
*
* @path_env: Path environment variable.
*
* Return: Original path or NULL
*/
char *check_empty_path(char *path_env)
{
	if (!path_env)
	{
		return (NULL);
	}

	if (strlen(path_env) == 0)
	{
		free(path_env);
		return (NULL);
	}
	return (path_env);
}
