#include"main.h"
/**
 * prompt - print a prompt
 * Return: void
 */
void prompt(void)
{
	char *prp = "($) ";
	int i = 0;

	while (prp[i] != '\0')
	{
		_putchar(prp[i]);
		i++;
	}
}
/**
 * exccommand - execute a coomand
 * @argv: pointer to a ponter to string
 * Return: void
 */

int main(__attribute__((unused)) int ac, char **av, char **envp)
{
	char *lineptr = "NULL", *input = "NULL", **argv;
	size_t n = 0;
	ssize_t ntyped;
	pid_t cpid;
	int size, status;
	
	while (1)
	{
		prompt();
		ntyped = getline(&lineptr, &n, stdin);
		if (ntyped == -1)
		{
			_putchar('\n');
			return (-1);
		}
		/*create a child process*/
		cpid = fork();
		if (cpid == -1)
		{
			perror("Error");
			return (-1);
		}
		if (cpid == 0)
		{
			size = _strlen(lineptr);
			lineptr[size - 1] = '\0';
			argv[0] = lineptr;
			argv[1] = NULL;
			execve(argv[0], argv, envp);
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
