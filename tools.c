#include "main.h"

/**
* freearr - free a 2d array
*
* @arr: array to be tested
*
*/

void freearr(char **arr)
{
	int i = 0;

	if (!arr)
		return;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr), arr = NULL;
}
/**
* free_speech - free a 2d array
*
* @tokens: tokens to be tested
*
*/
void free_speech(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)

	{
		free(tokens[i]);
	}

	free(tokens);
}

/**
* print_error - print an error message to stderr
*
* @program_name: the name of the program
* @command: the command causing the error
* @line_number: the line number
*/
void print_error(char *program_name, char *command, int line_number)
{
	char error_msg[] = ": not found\n";
	char line_number_str[20];
	int length = 0, i;
	int num = line_number;
	int temp = num;

	if (num < 0)
	{
		line_number_str[length++] = '-';
		num = -num;
	}

	do {
		length++;
		temp /= 10;
	} while (temp > 0);

	for (i = length - 1; i >= 0; i--)
	{
		line_number_str[i] = '0' + (num % 10);
		num /= 10;
	}
	line_number_str[length] = '\0';

	write(STDERR_FILENO, program_name, strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line_number_str, strlen(line_number_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, error_msg, strlen(error_msg));
}

/**
* display_prompt - display the dollar sign
*
*/

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		putchar('$');
		putchar(' ');
		fflush(stdout);
	}
}
