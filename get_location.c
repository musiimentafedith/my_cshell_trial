#include"main.h"
/**
 * get_location - return path of the command
 * @command - command whoes path is to be returned
 * Return: char pointer
 */

char *get_location(char *command)
{
	char *path = NULL, *cpy_path, *delim = ":", *path_token, *command_path;
	int command_len, path_token_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		/*allocate memory for cpy_path*/
		cpy_path = malloc(sizeof(char) * (_strlen(path) + 1));
		/*get a copy of path */
		_strcpy(cpy_path, path);
		/*generate path for the given command*/
		/*first get the comman length*/
		command_len = _strlen(command);
		/*tokenize the path*/
		path_token = strtok(cpy_path, delim);
		while (path_token != NULL)
		{
			/*get path_token length*/
			path_token_len = _strlen(path_token);
			/*allocte memory to store combination of path_token and command*/
			command_path = malloc(command_len + path_token_len + 2);
			/*build path for the command*/
			_strcpy(command_path, path_token);
			strcat(command_path, "/");
			strcat(command_path, command);
			strcat(command_path, "\0");
			/*test if the command path exists, and return it if it does*/
			if (stat(command_path, &buffer) == 0)
			{
				free(cpy_path);
				return (command_path);
			}
			else
			{
				free(command_path);
				path_token = strtok(NULL, delim);
			}
		}	
		free(cpy_path);
		/*we check if the command its self is a command path that exisits*/
		if (stat(command, &buffer) == 0)
		{	
			return (command);
		}
		else
		{
			return (NULL);
		}
	}
	return (NULL);
}
