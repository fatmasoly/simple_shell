#include "main.h"
/**
 * custom_atoi - Convert a string to an integer.
 * @str: The input string to be converted.
 *
 * This function converts the input string @str to an integer. It skips any
 * leading non-digit characters and takes into account the sign of the number.
 * The function handles overflow conditions and returns the converted integer.
 *
 * Return: The converted integer.
 */
int custom_atoi(char *str)
{
int index = 0;
int count = 0;
int signFlag = 0;
unsigned int number = 0;
if (str == NULL)
return (0);
while (str[index] != '\0' && (str[index] > '9' || str[index] < '0'))
{
if (str[index] == '-')
++count;
++index;
}
while (str[index] != '\0' && str[index] <= '9' && str[index] >= '0')
{
number += str[index] - '0';
signFlag = 0;
if (number < (INT_MAX / 10 + 2))
{
number *= 10;
signFlag = 1;
}
++index;
}
if (signFlag)
number /= 10;
if (count % 2)
return (-number);
else
return (number);
}
/**
 * custom_strdup - Duplicate a string.
 * @source: The source string to be duplicated.
 *
 * This function duplicates the input string @source using dynamic memory
 * allocation. It returns a pointer to the newly allocated duplicate string.
 *
 * Return: A pointer to the duplicated string
 * or NULL if memory allocation fails.
 */
char *custom_strdup(char *source)
{
char *duplicate;
unsigned int index = 0, length = 0;
if (!source)
return (NULL);
while (source[length] != '\0')
length++;
duplicate = (char *)malloc((length + 1) * sizeof(char));
if (duplicate == NULL)
return (NULL);
while (index <= length)
{
duplicate[index] = source[index];
++index;
}
return (duplicate);
}
/**
 * custom_strcmp - Compare two strings.
 * @string1: The first string to be compared.
 * @string2: The second string to be compared.
 *
 * This function compares the strings @string1 and @string2. It returns 0 if
 * the strings are equal and a non-zero value otherwise. The function handles
 * NULL input strings appropriately.
 *
 * Return: 0 if strings are equal, non-zero otherwise.
 */
int custom_strcmp(const char *string1, const char *string2)
{
int index = 0, result = 1;
if (string1 == NULL || string2 == NULL)
return (0);
while (string1[index])
{
if (string1[index] != string2[index])
{
result = 0;
break;
}
index++;
}
return (result);
}
/**
 * custom_strlen - Get the length of a string.
 * @str: The input string.
 *
 * This function calculates and returns the length of the input string @str.
 * It handles NULL input strings and returns 0 for them.
 *
 * Return: The length of the string.
 */
int custom_strlen(char *str)
{
int count = 0;
if (str == NULL)
return (0);
while (str[count] != '\0')
count++;
return (count);
}
/**
 * custom_strcpy - Copy a string.
 * @destination: The destination string.
 * @source: The source string to be copied.
 *
 * This function copies the string @source to the destination @destination.
 * It returns a pointer to the destination string. The function handles NULL
 * input strings appropriately.
 *
 * Return: A pointer to the destination string, or NULL if source is NULL.
 */
char *custom_strcpy(char *destination, char *source)
{
int destIndex = 0;
int sourceIndex = 0;
if (source == NULL || destination == NULL)
return (NULL);
while (source[sourceIndex] != '\0')
{
destination[destIndex] = source[sourceIndex];
destIndex++;
sourceIndex++;
}
destination[destIndex] = source[sourceIndex];
return (destination);
}

