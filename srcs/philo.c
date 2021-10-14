/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:15:49 by namenega          #+#    #+#             */
/*   Updated: 2021/10/14 16:38:46 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	destroy_mutex(t_philo *destroy)
{
	int	i;

	i = -1;
	while (++i < destroy->num_philo)
	{
		pthread_detach(destroy->philo[i]);
		pthread_mutex_destroy(&destroy->mutex[i]);
	}
	pthread_detach(destroy->thread_time);
	pthread_mutex_destroy(&destroy->write_mutex);
	pthread_mutex_destroy(&destroy->dead_mutex);
}

void	*routine(void *philo)
{
	t_philo	*ph;
	int		curr_philo;

	ph = get_struct();
	curr_philo = *(int *)philo;
	ph->left_fork = curr_philo;
	ph->right_fork = (ph->left_fork + 1) % ph->num_philo;
	if ((curr_philo % 2) == 0)
	{
		ph->right_fork = curr_philo;
		ph->left_fork = (ph->right_fork + 1) % ph->num_philo;
		usleep(500);
	}
	ph->actual_time[curr_philo] = what_time(ph);
	while (ph->death == 0)
	{
		thinking(curr_philo, ph);
		eating(curr_philo, ph);
		sleeping(curr_philo, ph);
	}
	return (NULL);
}

int	start(t_philo *philo)
{
	int	i;

	i = -1;
	philo->start_time = what_time(philo);
	pthread_mutex_lock(&philo->dead_mutex);
	pthread_create(&philo->thread_time, NULL, &time_routine, NULL);//!protect
	while (++i < philo->num_philo)
		pthread_create(&philo->philo[i], NULL, &routine, &philo->philo_id[i]);//!protect
	pthread_mutex_lock(&philo->dead_mutex);
	destroy_mutex(philo);
	return (0);
}
