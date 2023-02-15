/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:10:55 by gael              #+#    #+#             */
/*   Updated: 2023/02/15 15:12:18 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_minishell.h"

int	count_word(char *line)
{
	int	ite;
	int	len;
	int	is_quote;

	is_quote = -1;
	len = 0;
	ite = 0;
	while (line[ite])
	{
		// printf("line[%i]: %c\n", ite, line[ite]);
		while (ft_is_sep(line[ite]) == SUCCESS)
		{
			// printf(RED"in sep: line[ite]: %c\n"RST, line[ite]);
			ite++;
		}
		if (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL && is_quote == -1 )
		{
			// printf(GREEN"in len: line[%i]: %c\n"RST, ite, line[ite]);
			len++;
		}
		while (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL)
		{
			// printf("%i , %c\n", line[ite], line[ite]);
			if (line[ite] == 34) 
				is_quote *= -1;
			// if (line[ite] == 39)
			// 	is_quote *= -1;
			// printf(CYAN"no sep: line[ite]: %c\n"RST, line[ite]);
			ite++;
		}
		// printf("-------------------------------------------------\n");
	}
	return (len);
}

int	ft_find_args(t_mshell *mshell)
{
	printf("count_word(mshell->input): %i\n", count_word(mshell->input));
	// count_word(mshell->input);
	(void)mshell;
	return (SUCCESS);
}
