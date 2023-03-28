/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:19:01 by gael              #+#    #+#             */
/*   Updated: 2023/03/28 19:06:53 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

/*
echo abc"'def'"ghi'j'k"l"mnop
*/

char	*save_wo_qt(char **str_wo_qt, char **str, int *i_act)
{
	
	while ((*str)[(*i_act)] && ((*str)[(*i_act)] != D_QUOTE && (*str)[(*i_act) != S_QUOTE]))
	{
		printf(YELLOW"%c"RESET"", (*str)[(*i_act)]);
		(*i_act)++;
	}
	printf(" ");
	(void)str_wo_qt;
	(void)str;
	(void)i_act;
}

char	*write_without_qt(char *str)
{
	char	*str_wo_qt;
	int	i_act;

	i_act = 0;
	str_wo_qt = NULL;
	printf(BOLD_YELLOW"%s"RESET"\n", str);
	while (str[i_act])
	{
		save_wo_qt(&str_wo_qt, &str, &i_act);
		// printf(YELLOW"str_wo_qt: %p"RESET"\n", str_wo_qt);
		if (str[i_act])
			i_act++;
	}
	printf("\n");
	return (str);
}

int	isthere_quote(t_mini_sh *mini_sh)
{
	int	i_isthereqt;

	i_isthereqt = 0;
	while (mini_sh->rl_out->word[i_isthereqt])
	{
		if (mini_sh->rl_out->word[i_isthereqt] == D_QUOTE
			|| mini_sh->rl_out->word[i_isthereqt] == S_QUOTE)
			return (SUCCESS);
		i_isthereqt++;
	}
	return (FAIL);
}

void	remove_quote_2(t_mini_sh *mini_sh)
{
	t_mini_sh	*mini_tmp;
	char		*save;

	mini_tmp = mini_sh;
	mini_tmp->rl_out = mini_sh->rl_out_head;
	while (mini_tmp->rl_out)
	{
		if (isthere_quote(mini_sh) == SUCCESS)
		{
			save = ft_strdup(mini_tmp->rl_out->word);
			free(mini_tmp->rl_out->word);
			mini_tmp->rl_out->word = write_without_qt(save);
			// free(save);
		}
		mini_tmp->rl_out = mini_sh->rl_out->next;
	}
	(void)save;
}

