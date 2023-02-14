#include "ft_minishell.h"

void	ft_echo(char **str)
{
	int i;

	i = 0;
	if (ft_strncmp(str[0], "echo", 4) == 0)
	{
		if (ft_strncmp(str[1], "-n", 2) != 0)
		{		
			i = 1;
			while (str[i])
			{
				printf("%s ", str[i]);
				i++;
			}
			printf("\n");
		}
		else
		{
			i = 2;
			while (str[i])
			{
				printf("%s ", str[i]);
				i++;
			}
		}
	}
}