/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:21:41 by gael              #+#    #+#             */
/*   Updated: 2023/02/20 16:35:09 by gael             ###   ########.fr       */
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

void	expand(t_mini_sh *mini_sh)
{
	// t_arr_output	*mini_tmp;
	int				ite_expand;
	int				save;
	char			*new_str;
	// int		is_dquote;

	// is_dquote = FAIL;
	save = 0;
	new_str = NULL;
	mini_sh->rl_out = mini_sh->rl_out_head;
	while (mini_sh->rl_out)
	{
		ite_expand = 0;
		while (mini_sh->rl_out->word[ite_expand])
		{
			// if (mini_sh->rl_out->word[ite_expand] == D_QUOTE)
			// {
			// 	if (is_dquote == FAIL)
			// 		is_dquote = SUCCESS;
			// 	else
			// 		is_dquote = FAIL;
			// }
			// if (is_dquote == SUCCESS)
			// {
				if (mini_sh->rl_out->word[ite_expand] == '$')
				{
					save = ite_expand;
					ite_expand++;
					while (ft_is_valid_export(mini_sh->rl_out->word[ite_expand]) == SUCCESS)
						ite_expand++;
					new_str = ft_strdup_len(mini_sh->rl_out->word, 0, save);
					new_str = ft_strjoin(new_str, ft_find_var_env(mini_sh->env, ft_strdup_len(mini_sh->rl_out->word, save+1, ite_expand)));
					// printf(BACK_RED"new_str: %s"RST"\n", new_str);
					save = ite_expand;
					while (mini_sh->rl_out->word[ite_expand])
						ite_expand++;
					new_str = ft_strjoin(new_str, ft_strdup_len(mini_sh->rl_out->word, save, ite_expand));
					printf(BACK_RED"new_str: %s"RST"\n", new_str);
					free(mini_sh->rl_out->word);
					mini_sh->rl_out->word = new_str;
					// if (ft_isthere_dollar(mini_sh->rl_out->word) == SUCCESS)
					// 	expand(mini_sh);
				}
			// }
			ite_expand++;
		}
		// printf(BACK_GREEN"mini_sh->rl_out->word: %s"RST"\n", mini_sh->rl_out->word);
		mini_sh->rl_out = mini_sh->rl_out->next;
	}
	(void)new_str;
}
