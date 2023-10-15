#include "shell.h"
/**
* main -  entry into our program
* @argc: counting of arguments
* @argv: variables argument that are needed
* @env: variables enviroments
* Return: returns  integer
*/
int main(int argc, char *argv[], char **env)
{
(void) argc;
(void) argv;
int stat_exit;
size_t pos_nline;
size_t s;
char *cmd;

cmd = NULL;
stat_exit = 0;

while (1)
{
if (isatty(0) == 1)
prompt();

usercmd(&cmd, &s);

if (strcmp(cmd, "exit") == 0)
{
break;
}
else if (strncmp(cmd, "exit ", 5) == 0)
{
stat_exit = atoi(cmd + 5);
break;
}
else if (strcmp(cmd, "env") == 0 || strcmp(cmd, "printenv") == 0)
envprint(env);
executor(cmd);

pos_nline = strcspn(cmd, "\n");
if (pos_nline < s)
cmd[pos_nline] = '\0';

if (cmd != NULL)
cmd = NULL;
}

return (stat_exit);
}
