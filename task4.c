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
 * get_input - reads command from standard input
 *
 * Return: a string 
 */
char *get_input()
{
	char *input = NULL;
	size_t  n;
	ssize_t chars_typed;

	chars_typed = getline(&input, &n, stdin);
	if (chars_typed == -1)
	{
		_putchar('\n');
		exit(EXIT_SUCCESS);
	}
	return (input);
}

/**
 * tokenize - splite the input into commands
 * @input: input
 * Return: array of strings
 */

char **tokenize(char *input)
{
	char *input_copy, *token, *delim = " \n";
	char **argv;
	int i, ntokens;
	int buf_size = 64;


	/*allocate memory for input_copy*/
	//input_copy = malloc(sizeof(char) * (_strlen(input) + 1));
	//if (input_copy == NULL)
//	{
//		exit(EXIT_FAILURE);
//	}
	/*make a copy of input*/
//	_strcpy(input_copy, input);
	/*tokenize input_copy*/
//	token = strtok(input_copy, delim);
//	ntokens = 0;
//	while (token != NULL)
//	{
//		ntokens++;
//	}
//	ntokens++;
	/*allocate memory for array to hold the tokens */
	argv = malloc(sizeof(char *) * buf_size);
	if (argv == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(input, delim);
	/*store tokens to argv*/
	for (i = 0; token != NULL; i++)
	{
		/*allocate memory for argv[i]*/
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			exit(EXIT_FAILURE);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
//	free(argv);
//	free(input_copy);
	return (argv);
}

/**
 * execc - execute the command
 * @command: command to execute
 * Rteurn: an int
 */

int execc(char **argv)
{
	char *command, *actual_command;
	int i = 0;
	char *myexit = "exit";

	if (argv != NULL)
	{
		command = argv[0];
		if (strcmp(command, myexit) == 0)
		{
			exit(EXIT_SUCCESS);
		}
		actual_command = get_location(command);
		i = execve(actual_command, argv, NULL);
	}
	return (i);
}
/**
 * main - simple shell
 * @ac: number of arguments
 * @av: array of strings
 * Return: int
 */

int main(__attribute__((unused)) int ac, char **av)
{
	int status, i;
	struct stat buffer;
	pid_t cpid;
	char *input, *command;
	char **argv;

	while (1)
	{
		prompt();
		input = get_input();
		argv = tokenize(input);
		command = get_location(argv[0]);
		if (stat(command, &buffer) == 0)
		{
			cpid = fork();
			if (cpid == -1)
			{
				perror("Error");
				return (-1);
			}
			if (cpid == 0)
			{
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
		}
		else
		{
			return (0);
		}
	}
	free(argv);
	free(input);
	return (0);
}
