#include "main.h"
/**
 * shell_interactive - Enters interactive mode of the simple shell program.
 *
 * @prog: The name of the shell program.
 *
 * Description:
 *   This function implements the interactive mode of the simple shell program.
 *   It continuously prompts the user with a shell prompt, reads input from the
 *   standard input, and executes the entered command. The loop continues until
 *   the user exits the shell.
 *
 *   The function uses rd_getline to read a line from the standard input and
 *   splitString to tokenize the input into arguments. It then processes the
 *   command, handles built-in commands, and executes external commands using
 *   execute_command_helper.
 *
 * @prog: The name of the shell program.
 */
void shell_interactive(char *prog)
{
size_t buff_size = 0;
int  status = 0;
int line_num = 1;
char *buffer = NULL;
char **arguments = NULL;
char *pmt = "$ ";
(void)prog;
for (;;)
{
buffer = NULL, arguments = NULL, buff_size = 0;
/*Print the prompt ('$ ')*/
if (write(1, pmt, 2) == -1)
{
perror("Error writing to file descriptor");
exit(1);
}
/*Read a line from standard input*/
if (rd_getline(&buffer, &buff_size, STDIN_FILENO, 1) == -1)
exit(0);
/*Split the line into an array of strings*/
arguments = splitString(buffer, " \n\t");
/*Replace specific tokens in the array of strings*/
arguments = change_to(arguments, status);
free(buffer);
if (built_in_cmd(arguments, &status))
{
execute_command_helper(arguments, &status);
}
release_memory(arguments);
++line_num;
}
/*Close the shell*/
closing(NULL, status);
}
/**
 * execute_command_helper - Executes the given command with arguments.
 *
 * @arguments: The array of command-line arguments.
 * @status: Pointer to the exit status of the shell.
 *
 * Description:
 *   This function is responsible for executing the command specified by the
 *   user. It checks if the command is a valid executable file. If the command
 *   is not found, it attempts to find the command in the PATH using _find_cmd.
 *   If the command is found, cmd_execution is called to create a child process
 *   and execute the command. The exit status of the process is updated in the
 *   status variable.
 *
 * @arguments: The array of command-line arguments.
 * @status: Pointer to the exit status of the shell.
 */
void execute_command_helper(char **arguments, int *status)
{
char *cmd = NULL;
/*Check if the command exists and is executable*/
if (arguments[0] && access(arguments[0], F_OK | X_OK) == 0)
{
cmd_execution(arguments[0], arguments, status);
}
else if (arguments[0] == NULL)
{
 /* if the command is missing */
}
else
{
/*Find the full path of the command*/
cmd = _find_cmd(arguments[0]);
if (cmd == NULL)
{
perror("Command not found");
/*Set status to indicate command not found*/
*status = 127;
}
else
{
cmd_execution(cmd, arguments, status);
/*Free the memory allocated for the full path of the command*/
free(cmd);
}
}
}

