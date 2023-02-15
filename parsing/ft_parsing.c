/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:10:55 by gael              #+#    #+#             */
/*   Updated: 2023/02/15 16:50:17 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_minishell.h"

// int	count_word(char *line)
// {
// 	int	ite;
// 	int	len;
// 	int	is_quote;

// 	is_quote = -1;
// 	len = 0;
// 	ite = 0;
// 	while (line[ite])
// 	{
// 		while (ft_is_sep(line[ite]) == SUCCESS)
// 			ite++;
// 		if (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL && is_quote == -1)
// 			len++;
// 		while (line[ite] != '\0' && ft_is_sep(line[ite]) == FAIL)
// 		{
// 			if (line[ite] == D_QUOTE)
// 				is_quote *= -1;
// 			if (line[ite] == S_QUOTE)
// 				is_quote *= -1;
// 			ite++;
// 		}
// 	}
// 	return (len);
// }

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
			if (line[ite] == D_QUOTE)
			{
				ite++;
				while (line[ite] != D_QUOTE)
					ite++;
			}
			if (line[ite] == S_QUOTE)
			{
				ite++;
				while (line[ite] != S_QUOTE)
					ite++;
			}
			ite++;
		}
	}
	return (len);
}

int	ft_find_args(t_minish *minish)
{
	printf("\"abcdef\"$			%i-1\n", count_word("\"abcdef\""));
	printf("abcdef$				%i-1\n", count_word("abcdef"));
	printf("  \"abcdef\"  $			%i-1\n", count_word("  \"abcdef\"  "));
	printf("  abcdef  $			%i-1\n", count_word("  abcdef  "));
	printf("  abc\"def\"ghi  $		%i-1\n", count_word("  abc\"def\"ghi  "));
	printf("  abc\"def\"ghi  $		%i-1\n", count_word("  abc\"def\"ghi  "));
	printf("  \"abc def\"  $			%i-1\n", count_word("  \"abc def\"  "));
	printf("  abc def  $			%i-2\n", count_word("  abc def  "));
	printf("  0123 \"abc def\"  $		%i-2\n", count_word("  0123 \"abc def\"  "));
	printf("  0123 \"abc'def\" xyz'  $	%i-3\n", count_word("  0123 \"abc'def\" xyz'  "));
	// count_word(minish->input);
	(void)minish;
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