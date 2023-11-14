#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;


char *read_line(void);
char *read_and_increment(int *status, int *line_number);
char **tokenize_command(char *input_line);
void freearr(char **arr);
int _execute(char **command, char **av, int command_index);
void display_prompt(void);
void populate_tokens(char **tokens, char *input_line, char *delimiter);
size_t count_tokens(char *input_line, char *delimiter);
void free_speech(char **tokens);
char *allocate_and_check(char *original);
char *get_env_value(char *env_entry, char *target_key);
char *_getenv(char *target_var);
char *_construct_full_cmd(char *dir, char *command);
char *check_absolute_path(char *command);
char *check_empty_path(char *path_env);
char *get_full_command_path(char *command);
void print_error(char *program_name, char *command, int line_number);
void wait_child_process(int *status);
int execute_command(char *full_path, char **command);
char *find_command_path(char *command, char **shell_name, int line_number);


#endif /* MAIN_H */
