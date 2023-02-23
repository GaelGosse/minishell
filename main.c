/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:26:23 by gael              #+#    #+#             */
/*   Updated: 2023/02/23 08:45:05 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

//main mael
// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	//(void)argv;
// 	//char *input;

// 	// while (1)
// 	// {
// 	// 	input = readline(">");
// 	// 	// process 
// 	// 	if (ft_strncmp(input, "exit", 4) == 0)
// 	// 		break ;
// 	// 	printf("input: %s\n", input);
// 	// }
// 	//printf("echo = %d\n", ft_echo(argv));
// 	ft_echo(argv);
// 	return (0);

// }


// main gael
int	main(int argc, char *argv[], char **envp)
{
	t_mini_sh	mini_sh;
	int	env_length;

	// mini_sh.env = envp;
	env_length = 0;
	while (envp[env_length])
		env_length++;
	mini_sh.env = (char **)malloc((sizeof (char *)) * (env_length + 1));
	env_length = -1;
	while (envp[++env_length])
	{
		mini_sh.env[env_length] = ft_strdup(envp[env_length]);
	}
	mini_sh.env[env_length] = 0;
	// while (1)
	// {
		mini_sh.output = NULL;
		// ft_find_args(&mini_sh, "ls -l --color=never 	 -a | /usr/bin/grep -i --color=never  	   in >     result.txt");
		// mini_sh.output = readline("\n\033[31m>\033[0m");
		// printf(BLUE"mini_sh.output: %s\n"RESET, mini_sh.output);
		// process 
		ft_find_args(&mini_sh);
		// if (ft_strncmp(mini_sh.output, "exit", 4) == 0)
		// 	break ;
	// }
	free_parsing(&mini_sh);
	free_env(&mini_sh);
	// env_length = -1;
	// while (mini_sh.env[++env_length])
	// {
	// 	free(mini_sh.env[env_length]);
	// }
	// free(mini_sh.env);
	(void)mini_sh;
	(void)argc;
	(void)argv;
	return (0);
}