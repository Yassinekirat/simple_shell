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
char **tokenize_command(char *line);
void freearr(char **arr);
int _execute(char **command, char **av, int idx);
void display_prompt(void);
void populate_tokens(char **tokens, char *line, char *delimiter);
size_t count_tokens(char *line, char *delimiter);
void free_speech(char **tokens);
char *allocate_and_check(char *value);
char *get_env_value(char *temp, char *env_var);
char *_getenv(char *env_var);
char *_construct_full_cmd(char *dir, char *command);
char *check_absolute_path(char *command);
char *check_empty_path(char *path_env);
char *_getpath(char *command);
void printerror(char *name, char *cmd, int idx);
void wait_child_process(int *status);
int execute_command(char *full_cmd, char **command);
char *find_cmd_path(char *command, char **av, int idx);


#endif /* MAIN_H */
