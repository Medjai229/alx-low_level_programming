#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
<<<<<<< HEAD
#define ERROR_NOREAD "Error: Can't read from file %s\n"
#define ERROR_NOWRITE "Error: Can't write to %s\n"
#define ERROR_NOCLOSE "Error: Can't close fd %d\n"

/**
 * main - copies the content of a file to another file
 * @argc: arguments counter
 * @argv: array of arguments
=======
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
>>>>>>> 2542cc1cd4a693f6e0ec9f6a99356cbb4ded9758
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from = 0, fd_to = 0;
	ssize_t b;
<<<<<<< HEAD
	char buff[BUF_SIZE_READ];
=======
	char buf[READ_BUF_SIZE];
>>>>>>> 2542cc1cd4a693f6e0ec9f6a99356cbb4ded9758

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
<<<<<<< HEAD
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
=======
	from_fd = open(av[1], O_RDONLY);
	if (from_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	to_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);

	while ((b = read(from_fd, buf, READ_BUF_SIZE)) > 0)
		if (write(to_fd, buf, b) != b)
			dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);
	if (b == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
>>>>>>> 2542cc1cd4a693f6e0ec9f6a99356cbb4ded9758

	fd_from = close(fd_from);
	fd_to = close(fd_to);
	if (fd_from)
		dprintf(STDERR_FILENO, ERROR_NOCLOSE, fd_from), exit(100);
	if (fd_to)
		dprintf(STDERR_FILENO, ERROR_NOCLOSE, fd_from), exit(100);

	return (0);
}
