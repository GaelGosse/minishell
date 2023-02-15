/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:48:45 by gael              #+#    #+#             */
/*   Updated: 2023/02/15 16:49:52 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

// ------------------------------ include ----------------------------------- //
# include "color.h"
// ---------------------------- end include --------------------------------- //

# define SUCCESS 1
# define FAIL -1

// ------------------------------ define ------------------------------------ //
# define D_QUOTE 34
# define S_QUOTE 39
// ---------------------------- end define ---------------------------------- //

typedef struct s_tab_output
{
	char	*word;
	
}		t_tab_output;

typedef struct s_minish
{
	char			*output;
	t_tab_output	tab_output;
	t_tab_output	tab_output_head;
}		t_minish;

//lib/ft_is_separator.c
int				ft_is_sep(char chr);
//lib/ft_strncmp.c
int				ft_strncmp(char *str, char *dest, int n);
//main.c
//parsing/ft_parsing.c
int				count_word(char *line);
int				ft_find_args(t_minish *minish);
//built_in/echo.c
int				ft_echo(char **str);
//built_in/cd.c
int				ft_strlen(char *str);

#endif