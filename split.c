#include "main.h"
/**
 * splitString - Split a string into an array of substrings.
 * @str: The input string to be split.
 * @delims: The delimiters to be used for splitting.
 *
 * This function takes an input string @str and splits it into an array of
 * substrings using the specified delimiters in @delims
 * It dynamically allocates memory for the resulting array
 * and each substring. The function returns the
 * array of substrings with a NULL terminator.
 *
 * Return: A dynamically allocated array of substrings, or NULL on failure.
 */
char **splitString(char *str, char *delims)
{
char **stringArray;
char *tok;
int wordCount = 0;
char *strCopy;
strCopy = custom_strdup(str);
stringArray = malloc(sizeof(char *) * 100);
tok = custom_strtok(strCopy, delims);
for (; tok != NULL ; wordCount++)
{
stringArray[wordCount] = malloc(sizeof(char) * custom_strlen(tok) + 1);
custom_strcpy(stringArray[wordCount], tok);
tok = custom_strtok(NULL, delims);
}
free(strCopy);
stringArray[wordCount] = NULL;
return (stringArray);
}