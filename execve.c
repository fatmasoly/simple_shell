#include "main.h"
/**
 * cmd_execution - Executes a command in a child process.
 *
 * @cmd: The command to execute.
 * @cmd_and_args: An array containing the command and its arguments.
 * @current_status: A pointer to the current status of the shell.
 *
 * Description:
 *   This function creates a child process using fork() and executes the
 *   specified command using execve(). If the execution fails, the current
 *   status is set to 2, and an error message is printed. The parent process
 *   waits for the child to complete and updates the current status if needed.
 *
 * Return:
 *   This function has no explicit return value.
 */
void cmd_execution(char *cmd, char **cmd_and_args, int *current_status)
{
pid_t child_process_id;
child_process_id = fork();
if (child_process_id == -1)
perror("Fork failed");
else if (child_process_id == 0)
{
if (execve(cmd, cmd_and_args, environ) == -1)
{
*current_status = 2;
perror("");
exit(2);
}
}
else if (child_process_id > 0)
{
if (wait(current_status) == -1)
perror("Wait failed");
if (*current_status != 0)
*current_status = 2;
}
}
/**
 * change_to - Replaces special tokens in command arguments.
 *
 * @arguments: An array of command arguments.
 * @current_status: The current status of the shell.
 *
 * Description:
 *   This function iterates through the array of command arguments and
 *   replaces special tokens like "$?", "$$", and environment variables
 *   with their corresponding values. It returns the modified arguments.
 *
 * Return:
 *   The modified array of command arguments.
 */
char **change_to(char **arguments, int current_status)
{
int index = 0;
for (index = 0; arguments[index] != NULL; ++index)
{
if (arguments[index][0] == '$' && arguments[index][1] != '\0')
{
if (arguments[index][1] == '?')
arguments[index] = out_to_stat(arguments[index], current_status);
else if (arguments[index][1] == '$')
arguments[index] = out_to_process_id(arguments[index]);
else
arguments[index] = out_to_enviro_variable(arguments[index]);
}
}
return (arguments);
}

