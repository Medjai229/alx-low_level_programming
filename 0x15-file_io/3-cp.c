#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERROR_NOREAD "Error: Can't read from file %s\n"
#define ERROR_NOWRITE "Error: Can't write to %s\n"
#define ERROR_NOCLOSE "Error: Can't close fd %d\n"

/**
 * main - copies the content of a file to another file
 * @argc: arguments counter
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd_from = 0, fd_to = 0;
	ssize_t b;
	char buff[BUF_SIZE_READ];

	if (argc != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, ERROR_NOREAD, argv[1]), exit(98);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, ERROR_NOWRITE, argv[2]), exit(99);

	while ((b = read(fd_from, buff, BUF_SIZE_READ)) > 0)
		if (write(fd_to, buff, b) != b)
			dprintf(STDERR_FILENO, ERROR_NOWRITE, argv[2]), exit(99);
	if (b == -1)
		dprintf(STDERR_FILENO, ERROR_NOREAD, argv[1]), exit(98);

	fd_from = close(fd_from);
	fd_to = close(fd_to);
	if (fd_from)
		dprintf(STDERR_FILENO, ERROR_NOCLOSE, fd_from), exit(100);
	if (fd_to)
		dprintf(STDERR_FILENO, ERROR_NOCLOSE, fd_from), exit(100);

	return (0);
}
