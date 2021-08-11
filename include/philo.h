/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:03:28 by pyg               #+#    #+#             */
/*   Updated: 2021/08/11 17:42:10 by namenega         ###   ########.fr       */
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
	int			num_philo;
	int			num_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_eat;
	long int	start_time;
	pthread_t	*philo;
}				t_philo;


/*
** MAIN_C
*/

int			main(int ac, char **av);
void		error_msg(char *s);

/*
** PARSING_C
*/

int			parsing(t_philo *philo, char **av);

/*
** PHILO_C
*/

int			philo(t_philo *ph);
void		*routine(void *arg);
long int	what_time(t_philo *ph);

/*
** UTILS_0_C
*/

int			ft_strlen(char *s);
void		ft_bzero(void *s, size_t size);
void		*ft_calloc(size_t size);
int			ft_atoi(const char *nptr);
t_philo		*get_struct(void);

#endif