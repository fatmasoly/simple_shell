#include "main.h"
/**
 * rd_getline - Custom implementation of getline with additional features.
 *
 * @line: Pointer to the buffer where the line is stored.
 * @line_size: Pointer to the size of the allocated buffer.
 * @file_de: File descriptor for reading input.
 * @reset_flag: Flag to reset the reading process.
 *
 * Description:
 *   This function reads a line from the specified file descriptor and stores
 *   it in the buffer pointed to by 'line'. The size of the allocated buffer
 *   is updated in 'line_size'. If 'reset_flag' is set, the function resets
 *   the read index and performs a new read operation. The function also
 *   handles interrupt signals by invoking 'handle_interrupt'.
 *
 * Return:
 *   On success, returns the size of the read line. On failure, returns -1.
 */
ssize_t rd_getline(char **line, size_t *line_size, int file_de, int reset_flag)
{
static int current_read = 0, read_index = 0, file_complete_flag = 1;
size_t char_index = 0;
static char buffer[10000];
if (reset_flag)
signal(SIGINT, handle_interrupt);
if (reset_flag || file_complete_flag)
current_read = read(file_de, buffer, 9988);
if (current_read == -1)
{
perror("");
return (-1);
}
buffer[current_read] = '\0';
if ((*line) == NULL)
(*line) = malloc(sizeof(char) * 1024);
for (; buffer[read_index] != '\0' &&
buffer[read_index] != '\n' && char_index < 1024 ; ++read_index)
{
if (buffer[read_index] == '\n' || buffer[read_index]
== ' ' || buffer[read_index] == '\t')
{
if (buffer[read_index + 1] == '\n' || buffer[read_index + 1]
== ' ' || buffer[read_index + 1] == '\t')
{
continue;
}
}
(*line)[char_index++] = buffer[read_index];
}
if (char_index == 0)
{
free((*line));
return (-1);
}
for (; buffer[read_index] == '\n' || buffer[read_index] == ' '
|| buffer[read_index] == '\t'; ++read_index)
(*line)[char_index] = '\0', *line_size = char_index;
return (*line_size);
}
/**
 * handle_interrupt - Signal handler for interrupt signals (SIGINT).
 *
 * @sig: The signal number.
 *
 * Description:
 *   This function is a signal handler for interrupt signals (e.g., SIGINT).
 *   It allows for graceful termination of the program when an interrupt
 *   signal is received. The function exits the program with status code 0.
 */
void handle_interrupt(int sig)
{
(void) sig;
exit(0);
}
