#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
char *line;
char **args;
int status;

if (!isatty(STDIN_FILENO))
{
line = read_line();
args = split_line(line);
status = execute(args);

free(line);
free(args);

return (status);
}
while (1)
{
printf("shell> ");
line = read_line();
args = split_line(line);
status = execute(args);

free(line);
free(args);

if (status == 0)
{
break;
}
}

return (0);
}
