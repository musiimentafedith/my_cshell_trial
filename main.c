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

int main(int ac, char **av)
{
	char *lineptr = "NULL"; char *cpy_lineptr = "NULL";
	size_t n = 0;
	ssize_t ntyped;
	char *token;
	char *delim = " \n";
	int ntokens, i, j;


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
		printf("%d\n", ntokens);

		
		/*allocate memory for av*/
		av = malloc(sizeof(char *) * ntokens);
		if (av == NULL)
			return (-1);
		/*store tokens to av*/
		token = strtok(cpy_lineptr, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * _strlen(token));
			if (av[i] == NULL)
				return (-1);
			_strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		
		execv(av);
		
		free(av);
		free(cpy_lineptr);
		free(lineptr);
	}
	return (0);
}

