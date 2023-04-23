#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>

int _putchar(char);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *get_location(char *command);

#endif
