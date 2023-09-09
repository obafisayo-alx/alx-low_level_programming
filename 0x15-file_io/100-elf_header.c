#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

#define ELF_MAGIC "\x7F\x45\x4C\x46"

int elf_file(const char *filename);
void read_elf_file(const char *filename);

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
        printf("ELF Header:\n\t");
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
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_err(filename);
    off_t origin_post;

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

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_err(filename);
    ssize_t byt_r = read(fd, &elf_header, sizeof(elf_header));
    if (byt_r != sizeof(elf_header))
    {
        close(fd);
        print_err(filename);
    }
    if (elf_header.e_ident[EI_CLASS] != ELFCLASS64)
    {
        printf("Not a 64-bit ELF file\n");
        close(fd);
        return;
    }
    printf("Magic:");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02X ", elf_header.e_ident[i]);
    }
    printf("\n");
    printf("Class: %d-bit\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
    printf("Data: %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "Little-endian" : "Big-endian");
    printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header.e_type);
    printf("Entry point address: 0x%lx\n", (unsigned long)elf_header.e_entry);
    close(fd);
}
