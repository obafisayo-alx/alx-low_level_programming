#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>

int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _read - read from a file and print an error message upon failure
 * @fd: the file descriptor to read from
 * @buf: the buf_arr to write to
 * @count: the number of bytes to read
 */
void _read(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	_close(fd);
	exit(98);
}

/**
 * _close - close a file descriptor and print an error message upon failure
 * @fd: the file descriptor to close
 */
void _close(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * elf_magic - ELF magics
 * @buf_arr: the ELF header
 */
void elf_magic(const unsigned char *buf_arr)
{
	unsigned int i;

	if (_strncmp((const char *) buf_arr, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < 16; ++i)
		printf("%02x%c", buf_arr[i], i < 15 ? ' ' : '\n');
}

/**
 * elf_class - ELF class
 * @buf_arr: the ELF header
 *
 * Return: bit mode (32 or 64)
 */
size_t elf_class(const unsigned char *buf_arr)
{
	printf("  %-34s ", "Class:");

	if (buf_arr[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buf_arr[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buf_arr[EI_CLASS]);
	return (32);
}

/**
 * elf_data - ELF datas is in
 * @buf_arr: the ELF header
 *
 * Return: 1 if big endian, otherwise 0
 */
int elf_data(const unsigned char *buf_arr)
{
	printf("  %-34s ", "Data:");

	if (buf_arr[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buf_arr[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * elf_version - ELF version is in
 * @buf_arr: the ELF header
 */
void elf_version(const unsigned char *buf_arr)
{
	printf("  %-34s %u", "Version:", buf_arr[EI_VERSION]);

	if (buf_arr[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - ELF OS/ABI is in
 * @buf_arr: the ELF header
 */
void elf_osabi(const unsigned char *buf_arr)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buf_arr[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buf_arr[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buf_arr[EI_OSABI]);
}

/**
 * elf_abivers -  ELF ABI version in is in
 * @buf_arr: the ELF header
 */
void elf_abivers(const unsigned char *buf_arr)
{
	printf("  %-34s %u\n", "ABI Version:", buf_arr[EI_ABIVERSION]);
}

/**
 * elf_type - ELF type
 * @buf_arr:  ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_type(const unsigned char *buf_arr, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type = 0x100 * buf_arr[16] + buf_arr[17];
	else
		type = 0x100 * buf_arr[17] + buf_arr[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - print entry point address
 * @buf_arr: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_entry(const unsigned char *buf_arr, size_t bit_mode, int big_endian)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (address_size && !*(buf_arr))
			--address_size, ++buf_arr;

		printf("%x", *buf_arr & 0xff);

		while (--address_size > 0)
			printf("%02x", *(++buf_arr) & 0xff);
	}
	else
	{
		buf_arr += address_size;

		while (address_size && !*(--buf_arr))
			--address_size;

		printf("%x", *buf_arr & 0xff);

		while (--address_size > 0)
			printf("%02x", *(--buf_arr) & 0xff);
	}

	printf("\n");
}

/**
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @av: the argument values
 *
 * Return: Always 0
 */
int main(int argc, const char *av[])
{
	unsigned char buf_arr[18];
	unsigned int bit_mode;
	int big_endian;
	int fd;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	_read(fd, (char *) buf_arr, 18);

	elf_magic(buf_arr);
	bit_mode = elf_class(buf_arr);
	big_endian = elf_data(buf_arr);
	elf_version(buf_arr);
	elf_osabi(buf_arr);
	elf_abivers(buf_arr);
	elf_type(buf_arr, big_endian);

	lseek(fd, 24, SEEK_SET);
	_read(fd, (char *) buf_arr, bit_mode / 8);

	elf_entry(buf_arr, bit_mode, big_endian);

	_close(fd);

	return (0);
}

/**
 * _strncmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}