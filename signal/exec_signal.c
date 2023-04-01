/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:07:31 by mael              #+#    #+#             */
/*   Updated: 2023/04/01 13:51:58 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	exec_signal(int index)
{
	if (index == 1)
	{
		signal(SIGINT, &handle_ctrl_c);
		signal(SIGQUIT, SIG_IGN);
	}
}
