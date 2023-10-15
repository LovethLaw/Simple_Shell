#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
int _putchar(char charact);
int _printf(const char *string);
void prompt(void);
void executor(const char *cmd);
void usercmd(char **cmd, size_t *s);
void envprint(char **env);
ssize_t _getlines(char **buffer, size_t *static_size);
#endif
