#include "main.h"
/**
 * main - Entry point for the simple shell program.
 *
 * @ac: The number of command-line arguments.
 * @av: An array containing the command-line arguments.
 *
 * Description:
 *   This function serves as the entry point for the simple shell program.
 *   It determines the mode of operation based on the number of arguments:
 *   - If there are two arguments, it enters script mode.
 *   - If there is one argument and the standard input is a terminal, it enters
 *     interactive mode.
 *   - If none of the above conditions is met, it enters non-interactive mode.
 *
 * Return:
 *   Always returns 0.
 */
int main(int ac, char **av)
{
/*Check the number of command-line arguments*/
if (ac == 2)
/*If there are 2 arguments, run the shell in script mode*/
script_mode(av[0], av[1]);
else if (ac == 1 && isatty(STDIN_FILENO))
{
/*If 1 argument and the input is a terminal, run shell in interactive mode*/
shell_interactive(av[0]);
}
else
{
/*If none of the above conditions are met, run shell in non-interactive mode*/
shell_non_interactive(av[0]);
}
return (0);
}

