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
/*Find the end of the destination string*/
while (destination[destIndex] != '\0')
{
destIndex++;
}
/*Copy characters from the source string to the destination string*/
while (source[sourceIndex] != '\0')
{
destination[destIndex] = source[sourceIndex];
destIndex++;
sourceIndex++;
}
destination[destIndex] = source[sourceIndex];
/*Return the concatenated string (destination)*/
return (destination);
}

