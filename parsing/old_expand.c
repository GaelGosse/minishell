// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   expand.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/19 02:21:41 by gael              #+#    #+#             */
// /*   Updated: 2023/02/28 11:58:43 by gael             ###   ########.fr       */ 
// /*                                                                            */
// /* ************************************************************************** */

// #include "../ft_minishell.h"

// void	replace_dollar(t_mini_sh * mini_sh)
// {
// 	int		i_replace;
// 	int		save;
// 	int		save2;
// 	char	*var_name;
// 	char	*final_var;

// 	final_var = 0;
// 	printf(BACK_CYAN"%s"RST"\n", mini_sh->rl_out->word);
// 	save = 0;
// 	save2 = 0;
// 	i_replace = 0;
// 	while (mini_sh->rl_out->word[i_replace] && mini_sh->rl_out->word[i_replace] != '$')
// 		i_replace++;
// 	save = i_replace;

// 	while (mini_sh->rl_out->word[i_replace] && ft_is_sep_expand(mini_sh->rl_out->word[i_replace]) == FAIL)
// 		i_replace++;
// 	save2 = i_replace;
	
// 	var_name = ft_strdup_len(mini_sh->rl_out->word, (save + 1), i_replace);
// 	final_var = ft_find_var_env(mini_sh->env, var_name);
// 	free(var_name);
// 	printf(BACK_PURPLE"%s"RST, ft_strdup_len(mini_sh->rl_out->word, 0, save));
// 	printf(BACK_GREEN"%s"RST, final_var);
// 	while (mini_sh->rl_out->word[i_replace])
// 		i_replace++;
// 	printf(BACK_PURPLE"%s"RST"\n\n", ft_strdup_len(mini_sh->rl_out->word, save2, i_replace));
// 	free(final_var);
// 	(void)save2;
// 	(void)var_name;
// 	(void)mini_sh;
// }

// int	print_interpreted(t_mini_sh *mini_sh)
// {
// 	int	i_isdollar;

// 	i_isdollar = -1;
// 	while (mini_sh->rl_out->word[++i_isdollar])
// 	{
// 		toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
// 		if ((mini_sh->is_dquote == SUCCESS || (mini_sh->is_dquote == FAIL && mini_sh->is_squote == FAIL)) && mini_sh->rl_out->word[i_isdollar] != '"' && mini_sh->rl_out->word[i_isdollar] != '\'')
// 		{
// 			// if (mini_sh->is_squote == FAIL)
// 			// 	printf(BACK_RED"is_squote: %i"RST"\n", mini_sh->is_squote);
// 			// else
// 			// 	printf(BACK_YELLOW"is_squote: %i"RST"\n", mini_sh->is_squote);
// 			// if (mini_sh->is_dquote == FAIL)
// 			// 	printf(BACK_RED"is_dquote: %i"RST"\n", mini_sh->is_dquote);
// 			// else
// 			// 	printf(BACK_YELLOW"is_dquote: %i"RST"\n", mini_sh->is_dquote);
// 			printf(BACK_YELLOW"%c"RST"", mini_sh->rl_out->word[i_isdollar]);
// 		}
// 		else
// 			printf(BACK_RED"%c"RST"", mini_sh->rl_out->word[i_isdollar]);
// 		// printf("-------------------------------------------------------\n");
// 		// toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
// 	}
// 	printf("\n");

// 	return (SUCCESS);
// 	(void)i_isdollar;
// 	(void)mini_sh;
// }

// int	ft_isthere_dollar(t_mini_sh *mini_sh)
// {
// 	int	i_isdollar;

// 	i_isdollar = -1;
// 	while (mini_sh->rl_out->word[++i_isdollar])
// 	{
// 		if (mini_sh->rl_out->word[i_isdollar] == '$')
// 		{
// 			return (SUCCESS);
// 		}
// 	}
// 	return (FAIL);
// 	(void)i_isdollar;
// 	(void)mini_sh;
// }
// // int	ft_isthere_dollar(t_mini_sh *mini_sh)
// // {
// // 	int	i_isdollar;
// // 	int	rtn_val;

// // 	rtn_val = FAIL;
// // 	i_isdollar = -1;
// // 	while (mini_sh->rl_out->word[++i_isdollar])
// // 	{
// // 		// toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
// // 		// if (mini_sh->is_dquote == SUCCESS && mini_sh->rl_out->word[i_isdollar] != '"')
// // 		// 	rtn_val = SUCCESS;
// // 		toggle_quote(mini_sh, mini_sh->rl_out->word[i_isdollar]);
// // 		if ((mini_sh->is_dquote == SUCCESS || (mini_sh->is_dquote == FAIL && mini_sh->is_squote == FAIL)) && mini_sh->rl_out->word[i_isdollar] != '"' && mini_sh->rl_out->word[i_isdollar] != '\'')
// // 			rtn_val = SUCCESS;
// // 	}
// // 	if (rtn_val == SUCCESS)
// // 		printf(BACK_GREEN"%s"RST"\n", mini_sh->rl_out->word);
// // 	return (rtn_val);
// // 	(void)i_isdollar;
// // 	(void)mini_sh;
// // }

// void	toggle_quote(t_mini_sh *mini_sh, char chr)
// {
// 	if (chr == S_QUOTE)
// 	{
// 		if (mini_sh->is_squote == FAIL)
// 			mini_sh->is_squote = SUCCESS;
// 		else
// 			mini_sh->is_squote = FAIL;
// 	}
// 	else if (chr == D_QUOTE && mini_sh->is_squote == FAIL)
// 	{
// 		if (mini_sh->is_dquote == FAIL)
// 			mini_sh->is_dquote = SUCCESS;
// 		else
// 			mini_sh->is_dquote = FAIL;
// 	}
// }

// void	expand(t_mini_sh *mini_sh)
// {
// 	int	ite = 0;
// 	int	tt = 0;
// 	mini_sh->rl_out = mini_sh->rl_out_head;
// 	while (mini_sh->rl_out)
// 	{
// 		// printf(BACK_GREEN"mini_sh->rl_out->word: %s"RST"\n", mini_sh->rl_out->word);
// 		ite = -1;
// 		tt = 0;
// 		while (mini_sh->rl_out->word[++ite])
// 		{
// 			if (mini_sh->rl_out->word[ite] == '$')
// 			{
// 				tt = 1;
// 			}
// 		}
// 		if (tt > 0)
// 			print_interpreted(mini_sh);

// 		// make is there a dollar like above
// 		// if (ft_isthere_dollar(mini_sh) == SUCCESS)
// 		// 	replace_dollar(mini_sh);
// 		mini_sh->rl_out = mini_sh->rl_out->next;
// 	}
// }
