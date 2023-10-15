#include "shell.h"
/**
* usercmd -  entered by the user
* @cmd:  parsed cmd
* @s: cmd read
*/
void usercmd(char **cmd, size_t *s)
{
ssize_t readcmd;

readcmd = _getlines(cmd, s);

if (readcmd == -1)
{
if (*cmd == NULL)
{
perror("getline");
exit(EXIT_FAILURE);
}

if (feof(stdin))
{
_printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

if ((*cmd)[readcmd - 1] == '\n')
{
(*cmd)[readcmd - 1] = '\0';
*s = strlen(*cmd);
}
}
