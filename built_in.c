#include "main.h"
/**
 * built_in_cmd - Executes built-in commands.
 * @args: Array of command arguments.
 * @progStatus: Pointer to the program status.
 *
 * Description:
 *   This function checks if the provided command is a built-in command and
 *   executes the corresponding action. Supported built-in commands include
 *   "exit," "env," and "cd."
 *
 * Return:
 *   Returns 1 if a built-in command is executed, 0 otherwise.
 */
int built_in_cmd(char **args, int *progStatus)
{
int isFlagged = 1;
if (custom_strcmp(args[0], "exit") == 1)
{
closing(args, *progStatus);
isFlagged = 0;
}
else if (custom_strcmp(args[0], "env") == 1)
{
display_env();
isFlagged = 0;
}
else if (custom_strcmp(args[0], "cd") == 1)
{
isFlagged = 0;
}
return (isFlagged);
}
/**
 * closing - Handles the 'exit' command, terminating the program.
 * @arguments: Array of command arguments.
 * @status: Exit status of the program.
 *
 * This function handles the 'exit' command, allowing the user to terminate
 * the program with an optional exit status.
 *
 * If no argument is provided, the program exits with the current status.
 * If a non-negative integer is provided, the program exits with that status.
 * Otherwise, an error message is displayed
 * and the program exits with status 2.
 */
void closing(char **arguments, int status)
{
int number = -1;
if (!arguments || !arguments[1])
{
release_memory(arguments);
exit(status);
}
number = custom_atoi(arguments[1]);
if (number >= 0)
{
release_memory(arguments);
exit(number);
}
else
{
perror("Invalid number");
release_memory(arguments);
exit(2);
}
}
/**
 * display_env - Displays the environment variables.
 *
 * This function iterates through the environment variables and writes each
 * variable to the standard output along with a newline character. It uses the
 * global variable 'environ' to access the environment variables.
 */
void display_env(void)
{
char newline = '\n';
int index = 0;
for (index = 0; *(environ + index) != NULL; ++index)
{
if (write(1, *(environ + index), strlen(*(environ + index))) == -1)
{
perror("Error occurred while writing to stdout");
}
if (write(1, &newline, 1) == -1)
{
perror("Error occurred while writing newline character");
}
}
}

