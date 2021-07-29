/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:03:28 by pyg               #+#    #+#             */
/*   Updated: 2021/07/15 19:10:02 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	int		num_philo;
	int		num_forks;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	int		num_of_eat;
}				t_philo;


/*
** MAIN_C
*/

int		main(int ac, char **av);
void	error_msg(char *s);

/*
** MAIN_C
*/

int		parsing(t_philo *philo, char **av);

/*
** UTILS_0_C
*/

int		ft_strlen(char *s);
void	ft_bzero(void *s, size_t size);
void	*ft_calloc(size_t size);
int		ft_atoi(const char *nptr);

#endif