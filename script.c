#include "main.h"
/**
 * script_mode - Execute commands from a file in script mode.
 * @prog: The program name (unused in the function).
 * @file: The name of the script file to be executed.
 *
 * This function opens the specified script file, reads its content
 * and executes the commands found in each line.
 * It uses the rd_getline function
 * to read lines, splits each line into arguments
 * and checks for built-in commands.If a command is not built-in
 * it searches for the command in the system's PATH
 * using _find_cmd and executes it using cmd_execution
 * The function handles errors related to file operations
 * and command execution, and it closes the file before
 * exiting. The status of the last executed command
 * is passed to the closing function.
 */
void script_mode(char *prog, char *file)
{
char **arguments = NULL, *buffer = NULL, *cmd = NULL;
size_t buff_size = 0;
int file_desc = open(file, O_RDONLY), line_num = 1, status = 0;
(void)prog;
if (file_desc == -1)
{
perror("Error opening file"), exit(127);
}
for (; rd_getline(&buffer, &buff_size, file_desc, 0) != -1;
++line_num, arguments = NULL, buff_size = 0, buffer = NULL, cmd = NULL)
{
arguments = splitString(buffer, " \n\t");
arguments = change_to(arguments, status), free(buffer);
if (built_in_cmd(arguments, &status))
{
if (arguments[0] && access(arguments[0], F_OK | X_OK) == 0)
cmd_execution(arguments[0], arguments, &status);
else if (arguments[0] == NULL)
{
}
else
{
cmd = _find_cmd(arguments[0]);
if (cmd == NULL)
{
perror("Command not found"), status = 127;
}
else
{
cmd_execution(cmd, arguments, &status), free(cmd);
}
}
}
release_memory(arguments);
}
if (close(file_desc) == -1)
{
perror("Error closing file"), exit(127);
}
closing(NULL, status);
}

