#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr:pointer to the memory previously allocated
 * @old_size:size of bytes allocated to ptr
 * @new_size:new size for ptr
 *
 * Return:ptr with new size if new size = 0 and ptr = null returns null
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i, copy_size;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size > old_size)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);

		/*calculating the min size to copy*/
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;

		/*copy the old data to the new memory*/
		for (i = 0; i < copy_size; i++)
			*((char *)new_ptr + i) = *((char *)ptr + i);

		free(ptr);
	}
	return (new_ptr);
}

