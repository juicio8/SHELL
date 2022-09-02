#include "shell.h"

char *read_line();
char **split_line(char *line);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *line;
	char **tokens;

	while (1)
	{
		PRINT("$ ");
		line = read_line();
		tokens = split_line(line);
		free(line);
		free(tokens);
	}
	
}


char *read_line() 
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);
	return (line);
}

#define DELIMETER " \n\t\r\a\v"
char **split_line(char *line)
{
	int i = 0;
	char **tokens;
	char *token;
	size_t capacity = 64;

	tokens = malloc(capacity * sizeof(char));
	if (tokens == NULL)
	{
		perror("There's an error");
		return (-1);
	}

	token = strtok(line, DELIMETER);

	while (token != NULL)
	{
		tokens[i] = token;
		PRINT(tokens[i]);
		PRINT("\n");
		i++;

		if (i >= capacity)
		{
			tokens = realloc(tokens, (capacity * 2) * sizeof(char));
		}

		token = strtok(NULL, DELIMETER);
	       	
	}
	tokens[i] = NULL;
	return tokens;
}
