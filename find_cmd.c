#include "main.h"
/**
 * _find_cmd - Locates the full path of a command in the PATH environment.
 *
 * @cmd: The command to find.
 *
 * Description:
 *   This function searches for the specified command in the directories
 *   listed in the PATH environment variable. It returns the full path if
 *   the command is found and executable; otherwise, it returns NULL.
 *
 * Return:
 *   If the command is found, the function returns the full path.
 *   If the command is not found or not executable, it returns NULL.
 */
char *_find_cmd(char *cmd)
{
int index = 0;
int found = 0;
char *get_path = _getenv("PATH");
char *find_in_path = NULL;
char **path_content = NULL;
if (!get_path)
return (NULL);
/*Split the PATH variable into an array of strings*/
path_content = splitString(get_path, ":\t\n");
if (!path_content)
return (NULL);
for (; path_content[index]; ++index)
{
/*Allocate memory for the full path of the command*/
find_in_path = malloc(custom_strlen(path_content[index])
+ custom_strlen(cmd) + 2);
if (!find_in_path)
return (NULL);
/*Construct the full path by concatenating directory and command*/
custom_strcpy(find_in_path, path_content[index]);
custom_strcat(find_in_path, "/");
custom_strcat(find_in_path, cmd);
if (find_in_path && access(find_in_path, F_OK | X_OK) == 0)
{
found = 1;
break;
}
free(find_in_path);
}
index = 0;
free(get_path);
release_memory(path_content);
if (found)
return (find_in_path);
else
return (NULL);
}
