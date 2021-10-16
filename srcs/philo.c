/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:15:49 by namenega          #+#    #+#             */
/*   Updated: 2021/10/16 19:04:48 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	destroy_mutex(t_philo *destroy)
{
	int	i;

	i = 0;
	while (i < destroy->num_philo)
	{
		if (pthread_detach(destroy->philo[i]) != 0)
			return (error_msg(ERR_DETACH));
		if (pthread_mutex_destroy(&(destroy->mutex[i])) != 0)
		{
			// printf("%d\n", i);
			return (-1);
		}
		i++;
	}
	if (pthread_detach(destroy->thread_time) != 0)
		return (error_msg(ERR_DETACH));
	// if (pthread_mutex_destroy(&(destroy->write_mutex)) != 0
	// 	|| pthread_mutex_destroy(&(destroy->dead_mutex)) != 0)
	// 	return (-1);
	pthread_mutex_destroy(&(destroy->write_mutex));
	pthread_mutex_destroy(&(destroy->dead_mutex));
		// return (error_msg(ERR_MUTEX_DESTROY));
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*ph;
	int		curr_philo;
	int		right_fork;
	int		left_fork;

	ph = get_struct();
	curr_philo = *(int *)philo;
	left_fork = curr_philo;
	right_fork = (left_fork + 1) % ph->num_philo;
	if ((curr_philo % 2) == 0)
	{
		right_fork = curr_philo;
		left_fork = (right_fork + 1) % ph->num_philo;
		usleep(200);
	}
	ph->actual_time[curr_philo] = what_time(ph);
	while (ph->death == 0)
	{
		eating(curr_philo, ph, left_fork, right_fork);
		sleeping(curr_philo, ph);
		thinking(curr_philo, ph);
	}
	return (NULL);
}

int	start(t_philo *philo)
{
	int	i;

	i = -1;
	philo->start_time = what_time(philo);
	if (pthread_mutex_lock(&philo->dead_mutex) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	if (pthread_create(&philo->thread_time, NULL, &time_routine, NULL) != 0)
		return (error_msg(ERR_CREATE));
	while (++i < philo->num_philo)
		if (pthread_create(&philo->philo[i], NULL, &routine,
				&philo->philo_id[i]) != 0)
			return (error_msg(ERR_CREATE));
	if (pthread_mutex_lock(&philo->dead_mutex) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	if (destroy_mutex(philo) == -1)
		return (-1);
	return (0);
}
