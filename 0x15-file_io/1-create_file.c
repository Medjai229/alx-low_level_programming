#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of file to create
 * @text_content: text to write
 *
 * Return: 1 on success 0 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0;
	ssize_t bytes = 0;

	if (filename == 0)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len] != 0)
			len++;

		bytes = write(fd, text_content, len);

		if (bytes == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
