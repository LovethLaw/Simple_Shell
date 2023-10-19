#include "shell.h"
/**
* executor - executes the command and creates a child process
* @cmdline: the command to be executed
*/
void executor(const char *cmdline);
void executor(const char *cmdline)
{
char *argsmm[128];
int count_arg = 0;
char *dmitter = " \n";
char *myenivment[] = {NULL};

pid_t childid = fork();

if (childid == -1)
{
perror("fork Error");
exit(EXIT_FAILURE);
}
else if (childid == 0)
{
char *tkn = strtok((char *)cmdline, dmitter);

while (tkn != NULL)
{
argsmm[count_arg++] = tkn;
tkn = strtok(NULL, dmitter);
}
argsmm[count_arg] = NULL;

if (strcmp(argsmm[0], "clear") == 0)
{
if (system("clear") == -1)
{
perror("clear");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}

if (strchr(argsmm[0], '/') != NULL)
{
if (execve(argsmm[0], argsmm, myenivment) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
char *penvs = getenv("PATH");
char *pcpy = strdup(penvs);
char *pths = strtok(pcpy, ":");

free(pcpy);
while (pths != NULL)
{
char pash[256];

snprintf(pash, sizeof(pash), "%s/%s", pths, argsmm[0]);
if (execve(pash, argsmm, myenivment) != -1)
{
exit(EXIT_SUCCESS);
}
pths = strtok(NULL, ":");
}

perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
