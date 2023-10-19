#include "shell.h"
/**
* _printf - stdout char
* @string: printed string
* Return: always an integer
*/
int _printf(const char *string)
{
	return (write(STDOUT_FILENO, string, strlen(string)));
}
