#ifndef MAIN_H
#define MAIN_H


#include <sys/types.h>

#define BUFFER_SIZE 1024
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
#endif /** MAIN_H*/