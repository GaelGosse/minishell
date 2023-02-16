/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:10:55 by gael              #+#    #+#             */
/*   Updated: 2023/02/16 15:07:25 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	build_result_output(t_mini_sh *mini_sh, char *line)
{
	t_tab_output	tab_output;
	int	len;

	len = check_quote_is_closed(line);
	if (len > 0)
	{
		while (line[ite])
		{
			while (ft_is_sep(line[ite]) == SUCCESS)
				ite++;
			if (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL)
				len++;
			while (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL)
			{
				if (quote_is_closed(line, &ite, D_QUOTE) == FAIL)
					return (FAIL);
				if (quote_is_closed(line, &ite, S_QUOTE) == FAIL)
					return (FAIL);
				ite++;
			}
		}
	}
	return ();
	(void)line;
	(void)len;
	(void)tab_output;
	(void)mini_sh;
}

int	ft_find_args(t_mini_sh *mini_sh)
{
	// test count_word
	printf("$				 %i 0\n------------------------------------------------\n", build_result_output(mini_sh, ""));
	printf("\"$				%i -1\n------------------------------------------------\n", build_result_output(mini_sh, "\""));
	printf("\"\"$				 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "\"\""));
	printf("\"e\"$				 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "\"e\""));
	printf("\"abcdef\"$			 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "\"abcdef\""));
	printf("abcdef$				 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "abcdef"));
	printf("  \"abcdef\"  $			 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "  \"abcdef\"  "));
	printf("  abcdef  $			 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "  abcdef  "));
	printf("  abc\"def\"ghi  $		 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "  abc\"def\"ghi  "));
	printf("  abc\"def\"ghi  $		 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "  abc\"def\"ghi  "));
	printf("  \"abc def\"  $			 %i 1\n------------------------------------------------\n", build_result_output(mini_sh, "  \"abc def\"  "));
	printf("  abc def  $			 %i 2\n------------------------------------------------\n", build_result_output(mini_sh, "  abc def  "));
	printf("  0123 \"abc def\"  $		 %i 2\n------------------------------------------------\n", build_result_output(mini_sh, "  0123 \"abc def\"  "));
	printf("  0123 \"abc'def\" xyz'  $	%i -1\n------------------------------------------------\n", build_result_output(mini_sh, "  0123 \"abc'def\" xyz'  "));

	
	(void)mini_sh;
	return (SUCCESS);
}

/*
int	count_word(char *line)
{
	int	ite;
	int	len;

	len = 0;
	ite = 0;
	while (line[ite])
	{
		while (ft_is_sep(line[ite]) == SUCCESS)
			ite++;
		if (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL)
			len++;
		while (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL)
		{
			printf("%c", line[ite]);
			ite++;
		}
	}
	return (len);
}
int main(void)
{
	char	*input;

	count_word("ls -l --color=never 	 -a | /usr/bin/grep -i --color=never  	   in >     result.txt");
	input = readline(">");
	printf("input: %s\n"RESET, input);
	return (0);
}
*/