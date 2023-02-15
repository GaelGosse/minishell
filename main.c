/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:26:23 by gael              #+#    #+#             */
/*   Updated: 2023/02/15 15:11:46 by gael             ###   ########.fr       */
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
int ft_test(void)
{
	printf("8: %i\n", 8);
	return (4);
}
int main(void)
{
	t_mshell	mshell;

	while (1)
	{
		mshell.input = NULL;
		// ft_find_args(&mshell, "ls -l --color=never 	 -a | /usr/bin/grep -i --color=never  	   in >     result.txt");
		mshell.input = readline("\n\033[31m>\033[0m");
		printf(BLUE"mshell.input: %s\n"RESET, mshell.input);
		// process 
		ft_find_args(&mshell);
		if (ft_strncmp(mshell.input, "exit", 4) == 0)
			break ;
	}
	return (0);
}