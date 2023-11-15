#include "main.h"
/**
 * custom_strcat - Concatenates two strings.
 * @destination: Pointer to the destination string.
 * @source: Pointer to the source string.
 *
 * Return: Pointer to the concatenated string.
 */
char *custom_strcat(char *destination, char *source)
{
int destIndex = 0;
int sourceIndex = 0;
if (destination == NULL)
return (source);
if (source == NULL)
return (destination);
for (; destination[destIndex] != '\0' ; destIndex++)
destination[destIndex] = '\0';
for (; source[sourceIndex] != '\0' ; destIndex++, sourceIndex++)
{
destination[destIndex] = source[sourceIndex];
}
destination[destIndex] = source[sourceIndex];
return (destination);
}

