#include "main h"

int main(int ac, char **av)
{
	char *prompter = "root_shell_krixx#: ";

	reader = 0;

	char *text = 0;
	ssize_t *desize = 0;
	int aloc = 0;
	(void)ac;
	char *text_copy = 0;
	const char *delim = " \n";
	char *token = 0;
	int counter = 0;
	int i;

	while (1)
	{
		printf("%s", prompter);
		aloc = getline(&text, &desize, stdin);
		if (aloc == -1)
		{
			perror("exiting shell...");
			return (-1);
		}

		text_copy = malloc((text) * 1);
		if (text_copy == NULL)
		{
			perror("memory allocation failed");
			return (-1);
		}
		else
		{
			strcpy(text_copy, text);
		}

		token = strtok(text, delim);
		if (token != NULL)
		{
			counter++;
			token = strtok(NULL, delim);
		}
		counter++;

		av = malloc(sizeof(char *) * counter);
		if (av == NULL)
		{
			perror("malloc");
			return (-1);
		}
		else
		{
			token = strtok(text_copy, delim);
			for (i = 0; token != NULL)
				av[i] = malloc(strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;

		printf("%s\n", text);

		free(text_copy);
		free(av);
		free(aloc);
		free(text);
	}

	return (0);
}
