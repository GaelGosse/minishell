/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:26:23 by gael              #+#    #+#             */
/*   Updated: 2023/02/16 01:43:23 by gael             ###   ########.fr       */
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
int main(void)
{
	t_mini_sh	mini_sh;

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
	(void)mini_sh;
	return (0);
}