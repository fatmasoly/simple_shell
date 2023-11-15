#include "main.h"
/**
 * shell_non_interactive - Handles non-interactive mode of the shell.
 *
 * @prog: Name of the shell program.
 *
 * Description:
 *   This function is responsible for executing the shell in non-interactive
 *   mode. It reads input from the standard input and processes each line as a
 *   command. The command is then executed using cmd_execution. If the command
 *   is a built-in command, it is executed directly. If the command is an
 *   executable file, it is executed using cmd_execution. If the command is not
 *   found, an error is displayed, and the exit status is set to 127.
 *
 * @prog: Name of the shell program.
 */
void shell_non_interactive(char *prog)
{
size_t buff_size = 0;
char **arguments = NULL;
char *buffer = NULL;
char *cmd = NULL;
int line_num = 1;
int status = 0;
(void)prog;
for (; rd_getline(&buffer, &buff_size, STDIN_FILENO, 0) != -1;
++line_num, arguments = NULL, buff_size = 0, buffer = NULL, cmd = NULL)
{
arguments = splitString(buffer, " \n\t");
arguments = change_to(arguments, status);
free(buffer);
if (built_in_cmd(arguments, &status))
{
if (arguments[0] && access(arguments[0], F_OK | X_OK) == 0)
cmd_execution(arguments[0], arguments, &status);
else if (arguments[0] == NULL)
{
/* If the command is missing */
}
else
{
cmd = _find_cmd(arguments[0]);
if (cmd == NULL)
{
perror("Command not found");
status = 127;
}
else
{
cmd_execution(cmd, arguments, &status);
free(cmd);
}
}
}
release_memory(arguments);
}
closing(NULL, status);
}

