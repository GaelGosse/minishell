/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:21:41 by gael              #+#    #+#             */
/*   Updated: 2023/02/28 11:58:43 by gael             ###   ########.fr       */ 
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	replace_dollar(t_mini_sh *mini_sh)
{
	int	i_redollar;

	i_redollar = 0;
	// while (mini_sh->)
	// {
		
	// }
	(void)i_redollar;
	(void)mini_sh;
}

int	ft_isthere_dollar(t_mini_sh *mini_sh)
{
	int	i_isdollar;

	i_isdollar = -1;
	while (mini_sh->rl_out->word[++i_isdollar])
	{
		toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
		if (mini_sh->is_dquote == SUCCESS && mini_sh->rl_out->word[i_isdollar] != '"')
		{
			printf(BACK_YELLOW"%c"RST, mini_sh->rl_out->word[i_isdollar]);
			replace_dollar(mini_sh);
		}
		else
			printf(BACK_RED"%c"RST, mini_sh->rl_out->word[i_isdollar]);
		// toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
	}
	printf("\n");

	return (1);
	(void)i_isdollar;
	(void)mini_sh;
}

void	toggle_quote(t_mini_sh *mini_sh, char chr)
{
	if (chr == S_QUOTE)
	{
		if (mini_sh->is_squote == FAIL)
			mini_sh->is_squote = SUCCESS;
		else
			mini_sh->is_squote = FAIL;
	}
	else if (chr == D_QUOTE && mini_sh->is_squote == FAIL)
	{
		if (mini_sh->is_dquote == FAIL)
			mini_sh->is_dquote = SUCCESS;
		else
			mini_sh->is_dquote = FAIL;
	}
}

void	expand(t_mini_sh *mini_sh)
{
	t_mini_sh	*mini_tmp;

	mini_tmp = mini_sh;
	mini_tmp->rl_out = mini_sh->rl_out_head;
	while (mini_tmp->rl_out)
	{
		// printf(BACK_GREEN"mini_tmp->rl_out->word: %s"RST"\n", mini_tmp->rl_out->word);
		ft_isthere_dollar(mini_sh);
		mini_tmp->rl_out = mini_tmp->rl_out->next;
	}
}