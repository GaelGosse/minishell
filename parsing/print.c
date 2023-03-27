/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:46:59 by gael              #+#    #+#             */
/*   Updated: 2023/03/27 15:08:18 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	print_word(char *new_w)
{
	int	x;

	x = 0;
	while (new_w[x])
	{
		printf(BACK_CYAN"%c"RST"", new_w[x]);
		x++;
	}
	printf(BACK_RED"%i"RST"\n", new_w[x]);
}

void	print_word2(char *new_w)
{
	int	x;

	x = 0;
	while (new_w[x])
	{
		printf(BACK_PURPLE"%c"RST"", new_w[x]);
		x++;
	}
	printf(BACK_YELLOW"%i"RST"\n", new_w[x]);
}

void	print_type(int type)
{
	if (type == CMD)
		printf(BLUE"CMD"RST"\n");
	else if (type == CMD_ABS)
		printf(BLUE"CMD_ABS"RST"\n");
	else if (type == PIPE)
		printf(BLUE"PIPE"RST"\n");
	else if (type == ARG)
		printf(BLUE"ARG"RST"\n");
	else if (type == REDIR_L)
		printf(BLUE"REDIR_L"RST"\n");
	else if (type == APPEND)
		printf(BLUE"APPEND"RST"\n");
	else if (type == HR_DOC)
		printf(BLUE"HR_DOC"RST"\n");
	else if (type == REDIR_R)
		printf(BLUE"REDIR_R"RST"\n");
	else if (type == OPTION)
		printf(BLUE"OPTION"RST"\n");
	else if (type == _FILE)
		printf(BLUE"_FILE"RST"\n");
	else if (type == BUILT_IN)
		printf(BLUE"BUILT_IN"RST"\n");
	else if (type == EOFL)
		printf(BLUE"EOFL"RST"\n");
	else if (type == _DIR)
		printf(BLUE"_DIR"RST"\n");
	else
		printf(BACK_RED"0"RST"\n");
}

void	ft_print_rl_out(t_mini_sh *mini_sh)
{
	t_parse	*tmp;

	tmp = mini_sh->rl_out_head;
	printf("START_PRINT\n");
	while (tmp)
	{
		print_word(tmp->word);
		if (tmp->type)
			print_type(tmp->type);
		printf("\n");
		tmp = tmp->next;
	}
	printf("END_PRINT\n");
}
