/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aristote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:14:18 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/13 16:43:09 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "Aristote.h"

void	do_tests(int count, char **params)
{
	char	*join; // a MUST for PHILO() macro
	char	**split; // a MUST for PHILO() macro
	int		philo_processus;
	int		fd;

	for (int i = 0 ; params[i] ; i++)
	{
		for (int j = 0 ; j++ < count ; )
		{
			PRINT_TEST(params[i], i);
			fd = open(TMP_FILE, O_RDONLY | O_CREAT | O_TRUNC, PERM);
			philo_processus = fork();
			if (!philo_processus)
			{
				fd = open(TMP_FILE, O_RDWR | O_TRUNC, PERM);
				dup2(fd, 1);
				close(fd);
				PHILO(params[i]);
			}
			else
			{
				sleep(3);
				kill(philo_processus, SIGKILL);
				printf("\e[32m%s\e[0m\n", get_next_line(fd));
				close(fd);
			}
		}
	}
}

char	**set_def_params()
{
	char	**ret;
	char	*join;

	join = NULL;
	join = ft_strjoin_free(join, TEST_DEFAULT0);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT1);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT2);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT3);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT4);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT5);
	join = ft_strjoin_free(join, "|");
	join = ft_strjoin_free(join, TEST_DEFAULT6);
	ret = ft_split(join, '|');
	free(join);
	return (ret);
}

char	**join_params(int ac, char **av)
{
	char	**ret;
	char	*join;

	if (atoi(av[1]))
	{
		av = &av[2];
		ac--;
	}
	else
		av = &av[1];
	join = NULL;
	for (int i = 0 ; i < ac - 1 ; i++)
	{
		join = ft_strjoin_free(join, av[i]);
		join = ft_strjoin_free(join, "|");
	}
	ret = ft_split(join, '|');
	free(join);
	return (ret);
}

void	parse(int ac, char **av, int *count, char *default_params)
{
	int	_atoi;

	_atoi = atoi(av[1]);
	if (ac == 2)
	{
		if (_atoi == 0)
			*default_params = 0;
		else
			*count = _atoi;
	}
	else
	{
		*default_params = 0;
		if (_atoi != 0)
			*count = _atoi;
	}
}

int	main(int ac, char **av)
{
	char	default_params;
	char	**params;
	int		count;

	count = 1;
	default_params = 1;
	if (ac >= 2)
		parse(ac, av, &count, &default_params);
	if (default_params == 0)
		params = join_params(ac, av);
	else
		params = set_def_params();
	do_tests(count, params);
	return (0);
}
