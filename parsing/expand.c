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

void	replace_dollar(t_mini_sh * mini_sh)
{
	int		i_replace;
	int		save;
	int		save2;
	char	*var_name;
	char	*final_var;

	final_var = 0;
	printf(BACK_CYAN"mini_sh->rl_out->word: %s"RST"\n", mini_sh->rl_out->word);
	save = 0;
	save2 = 0;
	i_replace = 0;
	while (mini_sh->rl_out->word[i_replace] && mini_sh->rl_out->word[i_replace] != '$')
		i_replace++;
	save = i_replace;

	while (mini_sh->rl_out->word[i_replace] && ft_is_sep_expand(mini_sh->rl_out->word[i_replace]) == FAIL)
		i_replace++;
	save2 = i_replace;
	
	var_name = ft_strdup_len(mini_sh->rl_out->word, (save + 1), i_replace);
	final_var = ft_find_var_env(mini_sh->env, var_name);
	free(var_name);
	printf(BACK_GREEN"-> %s"RST"\n", final_var);
	free(final_var);
	(void)save2;
	(void)var_name;
	(void)mini_sh;
}

int	print_interpreted(t_mini_sh *mini_sh)
{
	int	i_isdollar;

	i_isdollar = -1;
	while (mini_sh->rl_out->word[++i_isdollar])
	{
		toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
		if (mini_sh->is_dquote == SUCCESS && mini_sh->rl_out->word[i_isdollar] != '"')
		{
			printf(BACK_YELLOW"%c"RST, mini_sh->rl_out->word[i_isdollar]);
		}
		else
			printf(BACK_RED"%c"RST, mini_sh->rl_out->word[i_isdollar]);
		// toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
	}
	printf("\n");

	return (SUCCESS);
	(void)i_isdollar;
	(void)mini_sh;
}

int	ft_isthere_dollar(t_mini_sh *mini_sh)
{
	int	i_isdollar;
	int	rtn_val;

	rtn_val = FAIL;
	i_isdollar = -1;
	while (mini_sh->rl_out->word[++i_isdollar])
	{
		// toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
		// if (mini_sh->is_dquote == SUCCESS && mini_sh->rl_out->word[i_isdollar] != '"')
		// 	rtn_val = SUCCESS;
		toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
		if (mini_sh->is_dquote == SUCCESS && mini_sh->rl_out->word[i_isdollar] == '$')
			rtn_val = SUCCESS;
	}
	return (rtn_val);
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
	mini_sh->rl_out = mini_sh->rl_out_head;
	while (mini_sh->rl_out)
	{
		// printf(BACK_GREEN"mini_sh->rl_out->word: %s"RST"\n", mini_sh->rl_out->word);
		// print_interpreted(mini_sh);
		if (ft_isthere_dollar(mini_sh) == SUCCESS)
			replace_dollar(mini_sh);
		mini_sh->rl_out = mini_sh->rl_out->next;
	}
}
