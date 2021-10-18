/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:21:59 by namenega          #+#    #+#             */
/*   Updated: 2021/10/18 23:03:17 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/****************************** Handle dead timer *****************************/

static int	is_dead(t_philo *dead)
{
	int	i;

	i = -1;
	while (++i < dead->num_philo)
	{
		if (what_time(dead) - dead->start_eat_time[i] > dead->time_to_die)
		{
			dead->death = 1;
			if (pthread_mutex_lock(&dead->write_mutex) != 0)
				return (error_msg(ERR_MUTEX_LOCK));
			printf("%ld %d %s", what_time(dead), (i + 1), DIED);
			if (pthread_mutex_unlock(&dead->dead_mutex) != 0)
				return (error_msg(ERR_MUTEX_UNLOCK));
			return (-1);
		}
	}
	return (0);
}

/********************* Count number of time each philo eat ********************/

static int	count_eat(t_philo *philo)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < philo->num_philo)
		if (philo->meals[i] == philo->num_of_eat)
			philo->eat_enough_status[i] = 1;
	i = -1;
	while (++i < philo->num_philo)
		if (philo->eat_enough_status[i] == 1)
			count++;
	if (count == philo->num_philo)
	{
		philo->death = 1;
		if (pthread_mutex_lock(&philo->write_mutex) != 0)
			return (error_msg(ERR_MUTEX_LOCK));
		if (pthread_mutex_unlock(&philo->dead_mutex) != 0)
			return (error_msg(ERR_MUTEX_UNLOCK));
		return (-1);
	}
	return (0);
}

/******************************** Get real time *******************************/

long int	what_time(t_philo *ph)
{
	struct timeval	tv;
	long int		ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	ms = tv.tv_sec * 1000;
	ms += tv.tv_usec / 1000;
	return (ms - ph->start_time);
}

/*********************** Get more precision with sleep ************************/

void	ft_usleep(long int time_in_ms, t_philo *philo)
{
	long int	start_time;

	start_time = 0;
	start_time = what_time(philo);
	while ((what_time(philo) - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

/***************************** Routine around time ****************************/

void	*time_routine(void *time_arg)
{
	t_philo	*time_ph;

	(void)time_arg;
	time_ph = get_struct();
	while (time_ph->death == 0)
	{
		if (time_ph->num_of_eat > 0)
			if (count_eat(time_ph) == -1)
				return (NULL);
		if (is_dead(time_ph) == -1)
			return (NULL);
		ft_usleep(time_ph->death, time_ph);
	}
	return (NULL);
}
