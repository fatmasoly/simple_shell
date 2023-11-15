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
/*Check if forking was successful*/
if (child_process_id == -1)
perror("Fork failed");
else if (child_process_id == 0)
{
/*Attempt to execute the command with arguments*/
if (execve(cmd, cmd_and_args, environ) == -1)
{
*current_status = 2;
perror("");
exit(2);
}
}
else if (child_process_id > 0)
{
/*Code executed by the parent process*/
/*Wait for the child process to finish*/
if (wait(current_status) == -1)
perror("Wait failed");
if (*current_status != 0)
/*Set current_status to 2 if child process exited with an error*/
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
/*Loop through the array of strings until NULL is encountered*/
for (index = 0; arguments[index] != NULL; ++index)
{
if (arguments[index][0] == '$' && arguments[index][1] != '\0')
{
if (arguments[index][1] == '?')
/*Replace with the exit status*/
arguments[index] = out_to_stat(arguments[index], current_status);
else if (arguments[index][1] == '$')
/*Replace with the process ID*/
arguments[index] = out_to_process_id(arguments[index]);
else
/*Replace with an environment variable*/
arguments[index] = out_to_enviro_variable(arguments[index]);
}
}
/*Return the modified array of strings*/
return (arguments);
}

