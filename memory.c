#include "main.h"
/**
 * release_memory - Frees memory allocated for an array of strings.
 * @items: The array of strings to be freed.
 *
 * This function takes an array of strings and frees the memory allocated for
 * each string and the array itself. It checks for NULL before attempting to
 * free the memory to avoid segmentation faults.
 */
void release_memory(char **items)
{
int index = 0;
if (items == NULL)
return;
for (index = 0; items[index] != NULL; ++index)
free(items[index]);
free(items);
}
/**
 * _resize - Resizes memory allocated for a pointer.
 * @old_ptr: The pointer to the memory to be resized.
 * @size_before: The size of the memory before resizing.
 * @size_after: The size of the memory after resizing.
 *
 * This function resizes the memory allocated for a given pointer. It can
 * increase or decrease the size of the memory block or free it entirely. It
 * Return:
 * the new pointer to the resized memory. If resizing fails, it returns
 * NULL.
 */
void *_resize(void *old_ptr, unsigned int size_before, unsigned int size_after)
{
unsigned int index;
void *new_pointer = NULL;
if (size_after == size_before)
return (old_ptr);
if (size_after == 0)
if (old_ptr != NULL)
{
free(old_ptr);
return (NULL);
}
if (!old_ptr)
{
new_pointer = malloc(size_after);
if (!new_pointer)
return (NULL);
return (new_pointer);
}
if (size_after > size_before)
{
new_pointer = malloc(size_after);
if (new_pointer == NULL)
return (NULL);
while (index < size_before && index < size_after)
{
*((char *)new_pointer + index) = *((char *)old_ptr + index);
index++;
}
free(old_ptr);
}
return (new_pointer);
}

