/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:01:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/02/16 01:44:21 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	ft_echo(char **str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str[1], "echo", 4) == 0)
	{
		if (ft_strncmp(str[2], "-n", 2) != 0)
		{		
			i = 2;
			while (str[i])
				printf("%s ", str[i++]);
			printf("\n");
		}
		else
		{
			i = 3;
			while (str[i])
				printf("%s ", str[i++]);
		}
		return (SUCCESS);
	}
	return (FAIL);
}
