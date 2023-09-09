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
const char* get_elf_type_string(unsigned int type);

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

/**
 * read_elf_file - this function reads the elf file
 * @filename: name of file to be read
*/
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
    printf("%-34s 2's complement, %s\n  ","Data:", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "little endian" : "Big endian");
    printf("%-34s %d (current)\n  ","Version:", elf_header.e_ident[EI_VERSION]);
    elf_osabi(elf_header.e_ident);
    printf("%-34s %u\n  ", "ABI Version:", elf_header.e_ident[EI_ABIVERSION]);
    printf("%-34s %s\n  ", "Type:", get_elf_type_string(elf_header.e_type));
    printf("%-34s 0x%04lx\n  ","Entry point address:", (unsigned long)elf_header.e_entry & 0xFFFFFFFFUL);
    close(fd);
}

/**
 * elf_osabi - print ELF OS/ABI
 * @buffer: the ELF header
 */
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

	printf("%-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n  ", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n  ", buffer[EI_OSABI]);
}

/** get_elf_type_string - function to get a string representation of the 
 * EFL file type
 * @type: the value of the EFL type
*/
const char* get_elf_type_string(unsigned int type)
{
    switch (type) {
        case ET_NONE: return "NONE (No file type)";
        case ET_REL: return "REL (Relocatable file)";
        case ET_EXEC: return "EXEC (Executable file)";
        case ET_DYN: return "DYN (Shared object file)";
        case ET_CORE: return "CORE (Core file)";
        default: return "Unknown";
    }
}