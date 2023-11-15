#include "main.h"
/**
 * find_in_env - Finds the index of an environment variable.
 *
 * @nameToFind: The name of the environment variable to search for.
 *
 * Description:
 *   This function searches for the given environment variable name
 *   within the global 'environ' array and returns its index if found.
 *   If the variable is not found, it returns the index where it would
 *   be inserted. Memory is dynamically allocated during the process,
 *   and the caller is responsible for freeing it.
 *
 * Return:
 *   The index of the environment variable or the index where it would be
 *   inserted if not found.
 */
int find_in_env(const char *nameToFind)
{
char *currentToken = NULL;
char *environmentCopy = NULL;
int index = 0;
if (environ == NULL)
{
return (-1);
}
/*Iterate through the 'environ' array*/
for (index = 0; environ[index]; ++index)
{
/*Skip NULL entries in 'environ'*/
if (environ[index] == NULL)
{
continue;
}
/*Duplicate the environment entry for tokenization*/
environmentCopy = strdup(environ[index]);
if (environmentCopy == NULL)
{
perror("Error in strdup");
exit(EXIT_FAILURE);
}
/*Tokenize the entry to get the current variable name*/
currentToken = strtok(environmentCopy, "=");
if (currentToken != NULL && custom_strcmp(currentToken, nameToFind) != 0)
{
free(environmentCopy);
return (index);
}
free(environmentCopy);
}
return (-1);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 *
 * @nameToFind: The name of the environment variable to retrieve.
 *
 * Description:
 *   This function retrieves the value of the specified environment
 *   variable by finding its index and extracting the value. The result
 *   is a dynamically allocated string that must be freed by the caller.
 *   If the variable is not found, it returns NULL.
 *
 * Return:
 *   A dynamically allocated string containing the value of the
 *   environment variable, or NULL if not found.
 */
char *_getenv(const char *nameToFind)
{
char *envValue = NULL;
char *environmentCopy = NULL;
int Index = find_in_env(nameToFind);
if (environ[Index] == NULL)
return (NULL);
/*Duplicate the environment entry for further processing*/
environmentCopy = strdup(environ[Index]);
/*Tokenize the entry to get the environment variable's value*/
strtok(environmentCopy, "=");
envValue = strdup(strtok(NULL, "="));
/*Free the duplicated entry*/
free(environmentCopy);
return (envValue);
}

