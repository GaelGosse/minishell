
#include "ft_minishell.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *input;

	while (1)
	{
		input = readline(">");
		// process 
		if (ft_strncmp(input, "exit", 4) == 0)
			break ;
		printf("input: %s\n", input);
	}
	return (0);

}