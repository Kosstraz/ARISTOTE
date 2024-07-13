/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aristote.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:17:19 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/13 16:41:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARISTOTE_H
# define ARISTOTE_H

/*
		FILE SETTINGS
*/

# define PERM 0644
# define TMP_FILE ".aristote.tmp"

/*
		COLOR SPEC
*/

# define BOLD "\e[1m"
# define FORE_BLACK "\e[30m"
# define BACK_GREEN "\e[42m"
# define DEFAULT "\e[0m"

/*
		ALL DEFAULT TESTS
*/

# define TEST_DEFAULT0 "1 800 200 200" // died without eating
# define TEST_DEFAULT1 "5 800 200 200" // live
# define TEST_DEFAULT2 "5 800 200 200 7" // live
# define TEST_DEFAULT3 "4 410 200 200" //live
# define TEST_DEFAULT4 "4 310 200 100" //died
# define TEST_DEFAULT5 "3 310 200 100" //died
# define TEST_DEFAULT6 "3 610 200 100" //live
# define TEST_STRICT0 "4 400 200 200" // live (sometimes undefined behavior)
# define TEST_STRICT1 "200 800 200 200" // live
# define TEST_STRICT2 "5 800 200000 100" // died
# define TEST_STRICT3 "5 800 100 200000" // died

/*
		MORE SIMPLY TO CREATE TESTS
		create a 'char **split' var & create a 'char *join' (in the function) to work with this MACROS
*/

# define PHILO(args) join = ft_strjoin("philo ", args);\
					split = ft_split(join, ' ');\
					execve("../philo", split, NULL);\
					freemem((void **)split);\
					free(join);
# define PRINT_TEST(args, i) printf("\t\t%sTEST %d --> %s../philo %s%s\n ", BACK_GREEN, i, BOLD, args, DEFAULT)

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"

char	*get_next_line(int fd);
void	freemem(void **ptr2);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char sep);

#endif