#include "main.h"
/**
 * out_to_process_id - Generates a string with the process ID appended.
 *
 * @str: The input string.
 *
 * Description:
 *   This function takes an input string, extracts the process ID, converts
 *   it to a string, and appends it to the original string. The resulting
 *   string is dynamically allocated and must be freed by the caller.
 *
 * Return:
 *   A dynamically allocated string containing the original string
 *   with the process ID appended.
 */
char *out_to_process_id(char *str)
{
int processID = getpid();
size_t size = 0;
int j = 0;
int index = 2;
char *pidString = NULL;
char *end_Str = NULL;
pidString = (char *)malloc(sizeof(char) * 50);
end_Str = (char *)malloc(sizeof(char) * 600);
if (!pidString || !end_Str)
{
/* memory allocation error */
}
for (; str[index] != '\0'; ++index)
end_Str[j++] = str[index++];
end_Str[j] = '\0';
convert_int(pidString, processID);
size = custom_strlen(pidString) + custom_strlen(end_Str) + 1;
free(str);
str = (char *)malloc(sizeof(char) * size);
custom_strcpy(str, pidString);
custom_strcat(str, end_Str);
free(pidString);
free(end_Str);
return (str);
}
/**
 * out_to_stat - Generates a string with the status code appended.
 *
 * @str: The input string.
 * @currentStatus: The status code to be appended.
 *
 * Description:
 *   This function takes an input string, extracts a portion of it, converts
 *   the status code to a string, and appends it to the original string. The
 *   resulting string is dynamically allocated and must be freed by the caller.
 *
 * Return:
 *   A dynamically allocated string containing the original string
 *   with the status code appended.
 */
char *out_to_stat(char *str, int currentStatus)
{
size_t size = 0;
int j = 0;
int index = 2;
char *statusString = NULL;
char *end_Str = NULL;
statusString = (char *)malloc(sizeof(char) * 50);
end_Str = (char *)malloc(sizeof(char) * 600);
if (!statusString || !end_Str)
{
/* memory allocation error */
}
for (; str[index] != '\0'; ++index)
{
end_Str[j++] = str[index++];
}
end_Str[j] = '\0';
convert_int(statusString, currentStatus);
size = custom_strlen(statusString) + custom_strlen(end_Str) + 1;
free(str);
str = (char *)malloc(sizeof(char) * size);
custom_strcpy(str, statusString);
custom_strcat(str, end_Str);
free(statusString);
free(end_Str);
return (str);
}
/**
 * out_to_enviro_variable - Retrieves the value of an environment variable.
 *
 * @str: The input string containing the variable name.
 *
 * Description:
 *   This function takes an input string containing the name of an environment
 *   variable, retrieves its value, and returns a dynamically allocated string
 *   containing the value. If the variable is not found, an empty string is
 *   returned. The resulting string must be freed by the caller.
 *
 * Return:
 *   A dynamically allocated string containing the value of the
 *   environment variable.
 */
char *out_to_enviro_variable(char *str)
{
size_t size = 0;
int j = 0;
int index = 1;
char *envString = NULL;
char *end_Str = NULL;
end_Str = (char *)malloc(sizeof(char) * 600);
if (end_Str == NULL)
return (str);
for (; str[index] != '\0'; ++index)
{
end_Str[j++] = str[index++];
}
end_Str[j] = '\0';
envString = _getenv(end_Str);
if (!envString)
{
free(end_Str);
free(str);
str = (char *)malloc(sizeof(char) * 2);
str[0] = '\0';
return (str);
}
size = strlen(envString) + 1;
free(str);
str = (char *)malloc(sizeof(char) * size);
custom_strcpy(str, envString);
free(envString);
free(end_Str);
return (str);
}
/**
 * convert_int - Converts an integer to a string.
 *
 * @array: The character array to store the resulting string.
 * @number: The integer to be converted.
 *
 * Description:
 *   This function converts an integer to a string and stores the result in
 *   the provided character array. The resulting string is null-terminated.
 */
void convert_int(char *array, int number)
{
int isNegative = 0;
int j = 0;
int n = number;
int b;
int i = 0;
int digit = 0;
char a;
b = n;
for (; b >= 10; b /= 10, i++)
{
for (; i >= 0; i--)
{
digit = n / the_power(10, i);
if (i == 0 && isNegative == 1)
a = (digit % 10) + '1';
else
a = (digit % 10) + '0';
array[j] = a;
j++;
}
array[j] = '\0';
}
}
/**
 * the_power - Calculates the power of a base to an exponent.
 *
 * @base: The base value.
 * @exponent: The exponent value.
 *
 * Description:
 *   This function calculates the power of a base to a given exponent.
 *
 * Return:
 *  The result of base raised to the power of exponent.
 */
int the_power(int base, int exponent)
{
int result = base;
if (exponent == 0)
{
base = 1;
return (base);
}
while (--exponent)
base *= result;
return (base);
}

