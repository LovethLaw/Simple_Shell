#include "shell.h"
/**
* envprint - envs to stdout
* @env: environment variables
*/
void envprint(char **env)
{
int z;
char c = '\n';

for (z = 0; env[z] != NULL; z++)
{
_printf(env[z]);
_putchar(c);
}
}
