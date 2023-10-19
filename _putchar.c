#include "shell.h"
#include <unistd.h>
/**
* _putchar - character to stdout
* @charact: printing
* Return: integer
*/
int _putchar(char charact)
{
	return (write(STDOUT_FILENO, &charact, 1));
}
