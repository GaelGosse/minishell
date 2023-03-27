/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:33:25 by ggosse            #+#    #+#             */
/*   Updated: 2023/03/27 15:37:28 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>
#include <time.h>
#include "color.h"

int	main(int argc, char **argv){
	printf(PURPLE"access(test1, F_OK): %i"RESET"\n", access("test1", F_OK));
	printf(PURPLE"access(test1, X_OK): %i"RESET"\n", access("test1", X_OK));
	(void)argc;
	(void)argv;
}