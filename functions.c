#include"main.h"

/**
 * _putchar - prints a character
 * @c: character to print
 * Return: an int
 */
int  _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcpy - copy a string
 * src: source
 * @dest: destination
 * Return: char pointer
 */

char *_strcpy(char *dest, char *src)
{
	char *cpy;
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - calculates the string length
 * @str: string who lenth is needed
 * Return: int
 */
int _strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
