/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:26:23 by gael              #+#    #+#             */
/*   Updated: 2023/02/15 16:44:16 by gael             ###   ########.fr       */
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
	t_minish	minish;

	// while (1)
	// {
		minish.output = NULL;
		// ft_find_args(&minish, "ls -l --color=never 	 -a | /usr/bin/grep -i --color=never  	   in >     result.txt");
		// minish.output = readline("\n\033[31m>\033[0m");
		// printf(BLUE"minish.output: %s\n"RESET, minish.output);
		// process 
		ft_find_args(&minish);
		// if (ft_strncmp(minish.output, "exit", 4) == 0)
		// 	break ;
	// }
	(void)minish;
	return (0);
}