/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:56:44 by namenega          #+#    #+#             */
/*   Updated: 2021/10/14 19:37:34 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	eating(int curr_philo, t_philo *philo)
{
	int			i;
	long int	time_till_dead;

	i = -1;
	if (pthread_mutex_lock(&philo->mutex[philo->left_fork]) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	print_action(LEFT_FORK, philo, curr_philo + 1);
	if (pthread_mutex_lock(&philo->mutex[philo->right_fork]) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	if (philo->death == 0)
	{
		philo->actual_time[curr_philo] = what_time(philo);
		philo->meals[curr_philo]++;
		print_action(RIGHT_FORK, philo, (curr_philo + 1));
		print_action(EAT, philo, (curr_philo + 1));
		time_till_dead = what_time(philo);
		while (++i < (10 * philo->time_to_eat))
		{
			if (what_time(philo) - time_till_dead >= philo->time_to_eat)
				break ;
			usleep(100);
		}
	}
	if (pthread_mutex_unlock(&philo->mutex[philo->left_fork]) != 0)
		return (error_msg(ERR_MUTEX_UNLOCK));
	if (pthread_mutex_unlock(&philo->mutex[philo->right_fork]) != 0)
		return (error_msg(ERR_MUTEX_UNLOCK));
}
