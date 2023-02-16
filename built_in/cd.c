/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:01:39 by mlamarcq              #+#    #+#             */
/*   Updated: 2023/02/15 17:01:40 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	ft_strlen(char *str)
{
	int ite = 0;

	while (str[ite])
		ite++;
	return (ite):
}

int	pwd(char *str)
{
	printf("%s\n", getcwd(str, ft_strlen(str)));
}

int	ft_cd(int argc, char **str)
{
	char s[100];
	if (argc == 3)
	{
		if (ft_strncmp(str[1], "cd", 2) == 0)
		{
			if (chdir(str[2]) == 0)
			{
				printf("here\n");
				return (SUCCESS);
			}
			else
				return (FAIL);
		}
		else
			return (FAIL);
	}
	else
		printf("To use cd, you need only 3 arguments\n");
	return (FAIL);
}