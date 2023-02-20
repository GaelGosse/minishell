/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:04:44 by gael              #+#    #+#             */
/*   Updated: 2023/02/17 12:41:45 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

t_arr_output	*ft_lstnew_word(char *content)
{
	t_arr_output	*new;

	new = malloc(sizeof(t_arr_output));
	if (!new)
		return (NULL);
	new->word = content;
	new->next = NULL;
	return (new);
}

t_arr_output	*ft_lstnew_malloc(int size)
{
	t_arr_output	*new;

	new = malloc(sizeof(t_arr_output));
	if (!new)
		return (NULL);
	new->word = malloc(sizeof (char) * (size + 1));
	new->next = NULL;
	return (new);
}
