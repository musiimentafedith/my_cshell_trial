#include"main.h"
//extern char ** environ;

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
 * execc - execute command
 * @argv: command to execute
 * Return: void
 */
int execc(char **argv)
{
	char *command, *actual_command;
	int i;
	
	if (argv != NULL)
	{
		command = argv[0];
		actual_command = get_location(command);
		i = execve(actual_command, argv, NULL);
	}
	return (i);
}

int main(__attribute__((unused)) int ac, char **av)
{
        char *lineptr = "NULL"; char *cpy_lineptr = "NULL", **argv;
        size_t n = 0;
        ssize_t ntyped;
        char *token;
        char *delim = " \n";
        int ntokens, i, status;
	pid_t cpid;
	struct stat buffer;

        (void)ac;
        while (1)
        {
                prompt();
                ntyped = getline(&lineptr, &n, stdin);
                if (ntyped == -1)
                {
                        _putchar('\n');
			return (-1);
                }
		cpid = fork();
		if (cpid == -1)
		{
			perror("Error");
			return(-1);
		}
		if (cpid == 0)
		{
                	/*allocate memory for cpy_lineptr*/
                	cpy_lineptr = malloc(sizeof(char) * ntyped);
                	if (cpy_lineptr == NULL)
                        	return (-1);
                	/*make a copy of lineptr*/
                	_strcpy(cpy_lineptr, lineptr);
                	/*tokenize lineptr*/
                	token = strtok(lineptr, delim);
                	ntokens = 0;
                	while (token != NULL)
                	{
                        	ntokens++;
                        	token = strtok(NULL, delim);
                	}
                	ntokens++;
                	/*allocate memory for av*/
                	argv = malloc(sizeof(char *) * ntokens);
                	if (argv == NULL)
                       		 return (-1);
                	/*store tokens to av*/
                	token = strtok(cpy_lineptr, delim);
                	for (i = 0; token != NULL; i++)
                	{
               	         	argv[i] = malloc(sizeof(char) * _strlen(token));
		       		if (argv[i] == NULL)
                                	return (-1);
                        	_strcpy(argv[i], token);
                        	token = strtok(NULL, delim);
               	 	}	
                	argv[i] = NULL;
			i = execc(argv);
			if (i == -1)
			{
				perror(av[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
       // 	free(cpy_lineptr);
	//	free(lineptr);
	}
	free(cpy_lineptr);
	free(lineptr);
	return (0);
}

