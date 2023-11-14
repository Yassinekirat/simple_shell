#include "main.h"

/**
* allocate_and_check - Duplicate a string and check for allocation success.
*
* @original: Original string to be duplicated
*
* Return: Returns the duplicated string or NULL on failure
*/
char *allocate_and_check(char *original)
{
	char *duplicate = strdup(original);

	if (duplicate == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	return (duplicate);
}

/**
* get_env_value - Get the value of an environment variable.
*
* @env_entry: String to be tested
* @target_key: Key of the environment variable to retrieve
*
* Return: Returns the value of the environment variable or NULL if not found
*/
char *get_env_value(char *env_entry, char *target_key)
{
	char *key = strtok(env_entry, "=");

	char *value = strtok(NULL, "\n");

	if (key != NULL && strcmp(key, target_key) == 0)
	{
		if (value != NULL)
		{
			return (allocate_and_check(value));
		}
	}

	return (NULL);
}
