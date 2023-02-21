/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:21:41 by gael              #+#    #+#             */
/*   Updated: 2023/02/21 13:53:52 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	ft_isthere_dollar(char *str)
{
	int	ite_isdollar;

	ite_isdollar = -1;
	while (str[++ite_isdollar])
	{
		if (str[ite_isdollar] == '$')
			return (SUCCESS);
	}
	return (FAIL);
}

void	check_qt_open(t_arr_output *mini_tmp, int *ite_expand, int *is_dquote)
{
	if (mini_tmp->word[*ite_expand] == D_QUOTE)
	{
		if ((*is_dquote) == FAIL)
			(*is_dquote) = SUCCESS;
		else
			(*is_dquote) = FAIL;
	}
}

// void	ft_replace_dollar()
// {
	
// }

void	expand(t_mini_sh *mini_sh)
{
	t_arr_output	*mini_tmp;
	int				ite_expand;
	int				save;
	char			*new_str;
	int				is_dquote;

	is_dquote = FAIL;
	save = 0;
	new_str = NULL;
	mini_tmp = mini_sh->rl_out_head;
	while (mini_tmp)
	{
		ite_expand = 0;
		while (mini_tmp->word[ite_expand])
		{
			check_qt_open(mini_tmp, &ite_expand, &is_dquote);
			if (is_dquote == SUCCESS)
			{
				if (mini_tmp->word[ite_expand] == '$')
				{
					save = ite_expand;
					ite_expand++;
					while (ft_is_valid_export(mini_tmp->word[ite_expand]) == SUCCESS)
						ite_expand++;
					new_str = ft_strdup_len(mini_tmp->word, 0, save);
					new_str = ft_strjoin(new_str, ft_find_var_env(mini_sh->env, ft_strdup_len(mini_tmp->word, save+1, ite_expand)));
					save = ite_expand;
					while (mini_tmp->word[ite_expand])
						ite_expand++;
					new_str = ft_strjoin(new_str, ft_strdup_len(mini_tmp->word, save, ite_expand));
					free(mini_tmp->word);
					mini_tmp->word = new_str;
					if (ft_isthere_dollar(mini_tmp->word) == SUCCESS)
						expand(mini_sh);
				}
			}
			ite_expand++;
		}
		mini_tmp = mini_tmp->next;
	}
	(void)new_str;
}
