#include "main.h"

/**
* _getenv - Search for the value of a given environment variable.
*
* @target_var: The name of the environment variable to search for.
*
* Return: Returns the value of the environment variable or NULL if not found.
*/

char *_getenv(char *target_var)
{
	int index;
	char *env_entry, *value;

	for (index = 0; environ[index] != NULL; index++)
	{
		env_entry = strdup(environ[index]);

		if (env_entry == NULL)
		{
			perror("strdup");
			return (NULL);
		}

		value = get_env_value(env_entry, target_var);
		free(env_entry);

		if (value != NULL)
		{
			return (value);
		}
	}

	return (NULL);
}
