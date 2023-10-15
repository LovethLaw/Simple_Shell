#include "shell.h"
/**
* prompt - a prompt for users to enter argument command
*
*/
void prompt(void)
{
char cur_dir[1024];

if (getcwd(cur_dir, sizeof(cur_dir)) == NULL)
{
perror("getcwd");
exit(EXIT_FAILURE);
}
_printf(cur_dir);
_printf("$ ");
}
