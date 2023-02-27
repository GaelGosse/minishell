/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:48:45 by gael              #+#    #+#             */
/*   Updated: 2023/02/27 11:41:16 by gael             ###   ########.fr       */
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

// ------------------------------ define ------------------------------------ //
# define SUCCESS 1
# define FAIL -1
# define D_QUOTE 34
# define S_QUOTE 39
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_arr_output
{
	char				*word;
	int					type;
	struct s_arr_output	*next;
}						t_arr_output;

enum e_type
{
	CMD=1,
	PIPE,
	ARG,
	OPTION,
	REDIR_L,
	REDIR_R,
	_FILE
};

typedef struct s_mini_sh
{
	char			*output;
	char			**env;
	char			***prepare_exec;
	int				is_dquote;
	int				is_squote;
	t_arr_output	*rl_out;
	t_arr_output	*rl_out_head;
}					t_mini_sh;
// ---------------------------- end struct ---------------------------------- //

//lib/ft_lstadd_back.c
void			ft_lstadd_back(t_arr_output **lst, t_arr_output *new);
//lib/ft_cmp.c
int				ft_strcmp(char *str, char *dest);
int				ft_strncmp(char *str, char *dest, int n);
//lib/ft_strlen.c
int				ft_strlen(char *str);
//lib/ft_is_separator.c
int				ft_is_sep(char chr);
int				ft_is_sep_expand(char chr);
int				ft_is_valid_export(char chr);
int				ft_isalpha(int chr);
//lib/ft_split.c
char			**ft_split(const char *str, char sep);
//lib/ft_lstnew_word.c
t_arr_output *ft_lstnew_malloc(int size);
t_arr_output *ft_lstnew_word(char *content, int save, int ite);
//lib/ft_strjoin.c
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_w_free(char *s1, char *s2);
//lib/ft_strdup.c
char			*ft_strdup(char *str);
char			*ft_strdup_len(char *str, int start, int end);
//main.c
//free/free_parsing.c
void			free_env(t_mini_sh *mini_sh);
void			free_parsing(t_mini_sh *mini_sh);
void			ft_free_all(char *str, char **tab);
//parsing/expand.c
void			check_qt_open(char *line, int *i_expnd, int *is_qt);
void			expand(t_mini_sh *mini_sh);
int				ft_isthere_dollar(char *str);
void			ft_replace_dollar(t_mini_sh *mn_sh, t_arr_output *mn_tmp, int *i_expnd);
void			print_word(char *new_w);
void			print_word2(char *new_w);
//parsing/ft_find_path.c
int				ft_find_cmd(t_mini_sh *mini_sh, int ite_env);
int				ft_find_env(t_mini_sh *mini_sh);
int				ft_find_path(t_mini_sh *mini_sh);
char			*ft_find_var_env(char **envp, char *var_search);
//parsing/remove_quote.c
int				coun_without_qt(char *str);
void			remove_quote(t_mini_sh *mini_sh);
char			*write_without_qt(char *str);
//parsing/set_type.c
void			set_type(t_mini_sh *mini_sh);
//parsing/prepare_exec.c
int				count_double_arr(t_mini_sh *mini_sh);
void			prepare_exec(t_mini_sh *mini_sh);
//parsing/quote.c
int				check_quote_is_closed(char *line);
void			count_quote_arg(char *line, int *ite, int quote);
int				count_word(char *line);
int				quote_is_closed(char *line, int *ite, int quote);
//parsing/parsing.c
int				build_result_output(t_mini_sh *mini_sh, char *line);
int				ft_find_args(t_mini_sh *mini_sh);
void			ft_print_rl_out(t_mini_sh *mini_sh);
void			put_word_in_minish(t_mini_sh *mini_sh, char *line, int *save, int *ite);
//built_in/echo.c
int				ft_echo(char **str);
//built_in/cd.c
int				ft_cd(int argc, char **str);
int				pwd(char *str);

#endif