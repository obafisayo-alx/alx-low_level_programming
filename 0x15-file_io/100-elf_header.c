#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

#define ELF_MAGIC "\x7F\x45\x4C\x46"

int elf_file(const char *filename);
void read_elf_file(const char *filename);
void elf_osabi(const unsigned char *buffer);

/**
 * print_err - This function is used to print an error message
 * with an exit code of 98
 * @filename: This is the name of the file that caused an error
 */
void print_err(const char *filename)
{
    fprintf(stderr, "Error: This is not an ELF file %s\n", filename);
    exit(98);
}

/**
 * main - This is the main function
 * @argc: this is the number of arguments counted
 * @argv: This is an array of argument vectors passed
 * return is always 0
 */
int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    if (elf_file(argv[1]))
    {
        printf("ELF Header:\n  ");
        read_elf_file(argv[1]);
    }
    else
        print_err(argv[1]);
    return (0);
}

/**
 * elf_file - is a function that checks if the passed-in file name is an
 * ELF file
 * @filename: This is the filename passed as an argument into the file
 */
int elf_file(const char *filename)
{
    ssize_t byt_r;
    char magic_bytes[4];
    off_t origin_post;

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_err(filename);
    origin_post = lseek(fd, 0, SEEK_CUR);
    if (origin_post == -1)
    {
        close(fd);
        print_err(filename);
    }
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        close(fd);
        print_err(filename);
    }
    byt_r = read(fd, magic_bytes, sizeof(magic_bytes));
    if (byt_r != sizeof(magic_bytes))
    {
        close(fd);
        print_err(filename);
    }
    if (memcmp(magic_bytes, ELF_MAGIC, sizeof(magic_bytes)) == 0)
    {
        close(fd);
        return (1);
    }
    if (lseek(fd, origin_post, SEEK_SET) == -1)
    {
        close(fd);
        print_err(filename);
    }
    close(fd);
    return (0);
}

void read_elf_file(const char *filename)
{
    int i;
    Elf64_Ehdr elf_header;
    ssize_t byt_r;

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_err(filename);
    byt_r = read(fd, &elf_header, sizeof(elf_header));
    if (byt_r != sizeof(elf_header))
    {
        close(fd);
        print_err(filename);
    }
    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02X ", elf_header.e_ident[i]);
    }
    printf("\n  ");
    printf("%-34s ELF%d\n  ", "Class:", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
    printf("%-34s 2's complement, %s\n  ","Data:", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "Little-endian" : "Big-endian");
    printf("%-34s %d (current)\n  ","Version:", elf_header.e_ident[EI_VERSION]);
    elf_osabi(elf_header.e_ident);
    printf("%-34s %u\n  ", "ABI Version:", elf_header.e_ident[EI_ABIVERSION]);
    printf("%-34s %d\n  ", "Type:", elf_header.e_type);
    printf("%-34s 0x%lx\n  ","Entry point address:", (unsigned long)elf_header.e_entry);
    close(fd);
}
void elf_osabi(const unsigned char *buffer)
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

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}