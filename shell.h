#ifndef _SHELL_H_
#define _SHELL_H_

#define PRINT(c) (write(STDOUT_FILENO, c,_strlen(c)));
#include <unistd.h>
#include <stdlib.h>
