# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "color.h"

char	*ft_strdup_len(char *str, int start, int end)
{
	char	*res;
	int		ite_str;
	int		ite_res;

	ite_res = 0;
	ite_str = 0;
	while (str[ite_str])
		ite_str++;
	if (end > ite_str)
		return (NULL);
	res = malloc(sizeof (char) * ((end - start) + 1));
	if (!res)
		return (NULL);
	ite_str = start;
	while (ite_str < end)
	{
		res[ite_res] = str[ite_str];
		ite_res++;
		ite_str++;
	}
	res[ite_res] = '\0';
	return (res);
}

char	*ft_test(char *str)
{
	char *new;
	
	new = ft_strdup_len(str, 0, 4);
	return (new);
}

int	main(int argc, char *argv[], char** envp)
{
	char	*str = "abcdef";
	char	*final;

	final = ft_test(str);
	printf(BACK_GREEN"final: %s"RST"\n", final);
	free(final);
	// DIR   *dirp;
	// struct dirent *dp;
	// struct stat   stat_buffer;
	// char *path = "abc/def/xyz/";
	// dirp = opendir (path);
	// if (dirp == NULL)
	// {
	// 	if (S_ISREG(stat_buffer.st_mode))
	// 		printf(CYAN"%s\n"RST, path);
	// 	else
	// 		printf ("Cannot open directory '%s'\n", path);
	// 	return 1;
	// }

	// dp = readdir(dirp);
	// printf("%s\n", dp->d_name);
	// if ((dp = readdir(dirp)) == NULL)
	// {
	// 	printf(RED"%s\n"RST, path);
	// 	return (1);
	// }
	// stat(dp->d_name, &stat_buffer);
	// printf("%s\n", dp->d_name);
	// while ((dp = readdir(dirp)) != NULL)
	// {
	// 	printf(GREEN"%s\n"RST,dp->d_name);
	// }
	// closedir (dirp);
	(void)argc;
	(void)argv;
	(void)envp;
}