#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>


extern char **environ;

void shell_interactive(char *prog);
void shell_non_interactive(char *prog);
void script_mode(char *prog, char *file);
char *_find_cmd(char *cmd);
void cmd_execution(char *cmd, char **cmd_and_args, int *current_status);
char **change_to(char **arguments, int current_status);

ssize_t rd_getline
(char **line, size_t *line_size, int file_de, int reset_flag);

void handle_interrupt(int sig);
void release_memory(char **items);
void *_resize(void *old_ptr, unsigned int old_size, unsigned int new_size);
void convert_int(char *array, int number);
int the_power(int base, int exponent);
int find_in_env(const char *nameToFind);
char *_getenv(const char *nameToFind);
int built_in_cmd(char **args, int *progStatus);
void closing(char **arguments, int status);
void display_env(void);
int changeDirectory(char **args);
char *out_to_process_id(char *str);
char *out_to_stat(char *str, int currentStatus);
char *out_to_enviro_variable(char *str);
int custom_atoi(char *str);
int custom_strlen(char *str);
char *custom_strdup(char *source);
int custom_strcmp(const char *string1, const char *string2);
char *custom_strcpy(char *destination, char *source);
char *custom_strcat(char *destination, char *source);
char *custom_strncpy(char *destination, char *source, int limit);
char *custom_strncat(char *destination, char *source, int limit);

char **splitString(char *str, char *delims);
void execute_command_helper(char **arguments, int *status);
#endif
