/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:08 by gael              #+#    #+#             */
/*   Updated: 2023/04/01 13:39:35 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	ft_is_sep_parse(char chr)
{
	if ((int)chr == 32 || (int)chr == 9 || (int)chr == 124)
		return (SUCCESS);
	return (FAIL);
}

int	ft_is_sep_expand(char chr)
{
	if (chr == 32 || chr == 9 || chr == D_QUOTE || chr == S_QUOTE)
		return (SUCCESS);
	return (FAIL);
}

int	ft_isalpha(int chr)
{
	if (((chr >= 65) && (chr <= 90)) || ((chr >= 97) && (chr <= 122)))
		return (SUCCESS);
	return (FAIL);
}

int	valid_id(int chr)
{
	if ((ft_isalpha(chr) == SUCCESS) || (chr >= 48 && chr <= 57) || chr == '_')
		return (SUCCESS);
	return (FAIL);
}

int	ft_is_valid_export(char chr)
{
	if (ft_isalpha(chr) == SUCCESS || chr == '_')
		return (SUCCESS);
	return (FAIL);
}
