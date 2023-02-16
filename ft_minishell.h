/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:48:45 by gael              #+#    #+#             */
/*   Updated: 2023/02/16 14:22:32 by gael             ###   ########.fr       */
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
	char				*word;
	int					type;
	struct t_tab_output	*next;
}						t_tab_output;

typedef struct s_mini_sh
{
	char			*output;
	t_tab_output	tab_output;
	t_tab_output	tab_output_head;
}					t_mini_sh;

//lib/ft_is_separator.c
int				ft_is_sep(char chr);
//lib/ft_strncmp.c
int				ft_strncmp(char *str, char *dest, int n);
//main.c
//parsing/quote.c
int				check_quote_is_closed(char *line);
void			count_quote_arg(char *line, int *ite, int quote);
int				count_word(char *line);
int				quote_is_closed(char *line, int *ite, int quote);
//parsing/parsing.c
int				build_result_output(t_mini_sh *mini_sh, char *line);
int				ft_find_args(t_mini_sh *mini_sh);
//built_in/echo.c
int				ft_echo(char **str);
//built_in/cd.c
int				ft_strlen(char *str);

#endif