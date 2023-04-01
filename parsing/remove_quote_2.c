/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:19:01 by gael              #+#    #+#             */
/*   Updated: 2023/04/01 16:09:59 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

/*
echo abc"'def'"ghi'j'k"l"mn""op
*/

char	*write_without_qt(char *str)
{
	char	*str_wo_qt;
	int		i_act;
	int		last_qt;
	int	i_start;
	int	i_end;

	i_end = 0;
	i_start = 0;
	last_qt = 0;
	i_act = 0;
	str_wo_qt = NULL;
	while (str[i_act])
	{
		i_start = i_act;
		while (str[i_act] && (str[i_act] != D_QUOTE && str[i_act] != S_QUOTE))
			i_act++;
		i_end = i_act;
		last_qt = str[i_act];
		if (str[i_act])
			i_act++;
		if (str_wo_qt == NULL)
			str_wo_qt = ft_strdup_len(str, i_start, i_end);
		else
			str_wo_qt = ft_strjoin_dfree(str_wo_qt, ft_strdup_len(str, i_start, i_end));
		i_start = i_act;
		while (str[i_act] && str[i_act] != last_qt)
			i_act++;
		i_end = i_act;
		if (str_wo_qt == NULL)
			str_wo_qt = ft_strdup_len(str, i_start, i_end);
		else
			str_wo_qt = ft_strjoin_dfree(str_wo_qt, ft_strdup_len(str, i_start, i_end));
		if (str[i_act])
			i_act++;
	}
	if (str_wo_qt == NULL)
		str_wo_qt = str;
	return (str_wo_qt);
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



/*
int	save_wo_qt_first(char **str_wo_qt, char **str, int *i_act)
{
	int	i_start;
	int	i_end;

	i_start = (*i_act);
	while ((*str)[(*i_act)] && ((*str)[(*i_act)] != D_QUOTE && (*str)[(*i_act)] != S_QUOTE))
	{
		// printf(YELLOW"%c"RESET"", (*str)[(*i_act)]);
		// printf(PURPLE"%i"RESET" ", (*str)[(*i_act)] != D_QUOTE);
		// printf(PURPLE"%i"RESET"\n", (*str)[(*i_act)] != S_QUOTE);
		(*i_act)++;
	}
	// printf(YELLOW"(*str)[(*i_act)]: %i"RESET"\n", (*str)[(*i_act)]);
	i_end = (*i_act);
	// printf(BACK_RED" "RESET);
	// printf(PURPLE"malloc: %i"RESET"\n\n", i_end - i_start);
	if (i_end - i_start > 0)
	{
		if ((*str_wo_qt) == NULL)
			(*str_wo_qt) = ft_strdup_len((*str), i_start, i_end);
		else
			(*str_wo_qt) = ft_strjoin_dfree((*str_wo_qt), ft_strdup_len((*str), i_start, i_end));
	}	(void)str_wo_qt;
	(void)str;
	(void)i_act;
	return ((*str)[(*i_act)]);
}

int	save_wo_qt_rest(char **str_wo_qt, char **str, int *i_act, int last_qt)
{
	int		i_start;
	int		i_end;

	i_start = (*i_act);
		printf(YELLOW"%c"RESET"", (*str)[(*i_act)]);
		printf(PURPLE"%i"RESET" ", (*str)[(*i_act)] != D_QUOTE);
		printf(PURPLE"%i"RESET"\n", (*str)[(*i_act)] != S_QUOTE);
	while ((*str)[(*i_act)] && ((*str)[(*i_act)] != last_qt))
	{
		(*i_act)++;
	}
	i_end = (*i_act);
	// printf(BACK_RED" "RESET);
	printf(YELLOW"(*str)[(*i_act)]: %c"RESET"\n", (*str)[(*i_act)]);
	// printf(PURPLE"malloc: %i"RESET"\n\n", i_end - i_start);
	if (i_end - i_start > 0)
	{
		if ((*str_wo_qt) == NULL)
			(*str_wo_qt) = ft_strdup_len((*str), i_start, i_end);
		else
			(*str_wo_qt) = ft_strjoin_dfree((*str_wo_qt), ft_strdup_len((*str), i_start, i_end));
	}
	(void)str_wo_qt;
	(void)str;
	(void)i_act;
	return (-1);
}

char	*write_without_qt(char *str)
{
	char	*str_wo_qt;
	int		i_act;
	int		last_qt;

	last_qt = -1;
	i_act = 0;
	str_wo_qt = NULL;
	printf(BOLD_YELLOW"%s"RESET"\n", str);
	last_qt = save_wo_qt_first(&str_wo_qt, &str, &i_act);
	printf(PURPLE"last_qt: %i"RESET"\n\n", last_qt);
	while (str[i_act])
	{
		// printf(YELLOW"str_wo_qt: %p"RESET"\n", str_wo_qt);
		if (last_qt == -1)
		{
			last_qt = save_wo_qt_first(&str_wo_qt, &str, &i_act);
			printf(PURPLE"/\\last_qt: %i"RESET"\n\n", last_qt);
		}
		else
		{
			last_qt = save_wo_qt_rest(&str_wo_qt, &str, &i_act, last_qt);
			printf(PURPLE"\\/ last_qt: %i"RESET"\n\n", last_qt);
		}
		printf(GREEN"str_wo_qt: %s"RESET"\n\n", str_wo_qt);
		if (str[i_act])
			i_act++;
	}
	if (str_wo_qt == NULL)
		str_wo_qt = str;
	// printf(GREEN"%s"RESET"\n", str_wo_qt);
	// printf("\n");
	(void)last_qt;
	return (str);
}
*/