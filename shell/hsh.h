#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

char *_strdup(const char *str);
int _strlen(char *s);
char **split_string(const char *string);
int execute_file(char **args, struct stat *st, char **environ, char **argv);
bool check_file_status(char *pathname, struct stat *st, char **argv);

#endif /* SHELL_H **/
