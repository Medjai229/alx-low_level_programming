#include "main.h"
#include <elf.h>

/**
 * _checkelf - checks if file is elf or not
 * @h: elf header struct
 */
void _checkelf(Elf64_Ehdr h)
{
	if (h.e_ident[0] != 0x7f || h.e_ident[1] != 'E' ||
		h.e_ident[2] != 'L' || h.e_ident[3] != 'F')
		dprintf(STDERR_FILENO, "Error: Not elf file\n"), exit(98);
}

/**
 * _magic - print elf magic
 * @h: elf header struct
 */
void _magic(Elf64_Ehdr h)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < 15; i++)
		printf("%02x ", h.e_ident[i]);
	printf("%02x\n", h.e_ident[i]);
}

/**
 * _class - print elf class
 * @h: elf header struct
 */
void _class(Elf64_Ehdr h)
{
	printf("  %-35s", "Class:");
	switch (h.e_ident[EI_CLASS])
	{
	case ELFCLASS64:
		printf("ELF64");
		break;
	case ELFCLASS32:
		printf("ELF32");
		break;
	case ELFCLASSNONE:
		printf("none");
		break;
	}
	printf("\n");
}

/**
 * _data - print elf data
 * @h: elf header struct
 */
void _data(Elf64_Ehdr h)
{
	printf("  %-35s", "Data:");
	switch (h.e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian");
		break;
	}
	printf("\n");
}

/**
 * _version - print elf version
 */
void _version(Elf64_Ehdr h)
{
	printf("  %-35s", "Version:");

	if (h.e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", h.e_ident[EI_VERSION]);
	else if (h.e_ident[EI_VERSION] != EV_CURRENT)
		printf("%d\n", h.e_ident[EI_VERSION]);
}

/**
 * _os - print elf os
 * @h: elf header struct
 */
void _os(Elf64_Ehdr h)
{
	printf("  %-35s", "OS/ABI:");

	if (h.e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_AIX)
		printf("UNIX - AIX\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - Tru64\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_MODESTO)
		printf("UNIX - Novell Modesto\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_OPENBSD)
		printf("UNIX - OpenBSD\n");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App");
	else if (h.e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM");
	else
		printf("<unknown: %x>\n", h.e_ident[EI_OSABI]);

}

/**
 * _abiv - print elf abiversion
 * @h: elf header struct
 */
void _abiv(Elf64_Ehdr h)
{
	printf("  %-35s", "ABI Version:");
	printf("%d\n", h.e_ident[EI_ABIVERSION]);
}

/**
 * _type - print elf type
 * @h: elf header struct
 */
void _type(Elf64_Ehdr h)
{
	char *p = (char *)&h.e_type;
	int i = 0;

	printf("  %-35s", "Type:");
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		i = 1;
	switch (p[i])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", p[i]);
		break;
	}
	printf("\n");
}

/**
 * _entry - print elf entry
 * @h: elf header struct
 */
void _entry(Elf64_Ehdr h)
{
	int i = 0, len = 0;
	unsigned char *p = (unsigned char *)&h.e_entry;

	printf("  Entry point address:               0x");
	if (h.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		i = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[i])
			i--;
		printf("%x", p[i--]);
		for (; i >= 0; i--)
			printf("%02x", p[i]);
		printf("\n");
	}
	else
	{
		i = 0;
		len = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[i])
			i++;
		printf("%x", p[i++]);
		for (; i <= len; i++)
			printf("%02x", p[i]);
		printf("\n");
	}
}

/**
 * main -  displays the information contained in the ELF header
 * at the start of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: on success 0
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr h;
	ssize_t b;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Wrong number of Arguments\n"), exit(98);
	if (argv[1] == 0)
		dprintf(STDERR_FILENO, "Null name\n"), exit(98);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Can't Open File\n"), exit(98);
	b = read(fd, &h, sizeof(h));
	if (b == -1)
		dprintf(STDERR_FILENO, "Error Reading File\n"), exit(98);

	 _checkelf(h);
	 _magic(h);
	 _class(h);
	 _data(h);
	 _version(h);
	 _os(h);
	 _abiv(h);
	 _type(h);
	 _entry(h);

	if (close(fd))
		dprintf(STDERR_FILENO, "Error closing file\n"), exit(98);

	return (0);
}
