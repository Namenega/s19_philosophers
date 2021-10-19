/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:56:44 by namenega          #+#    #+#             */
/*   Updated: 2021/10/19 11:43:24 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/************************** Lock and eating process ***************************/

static int	eating_action(int curr_philo, t_philo *philo)
{
	int			i;
	long int	time_till_dead;

	i = -1;
	philo->start_eat_time[curr_philo] = what_time(philo);
	philo->meals[curr_philo]++;
	if (print_action(RIGHT_FORK, philo, (curr_philo + 1)) == -1)
		return (-1);
	if (print_action(EAT, philo, (curr_philo + 1)) == -1)
		return (-1);
	time_till_dead = what_time(philo);
	ft_usleep(philo->time_to_eat, philo);
	return (0);
}

/************************** Lock and eating process ***************************/

int	eating(int curr_philo, t_philo *philo, int left_fork, int right_fork)
{
	if (pthread_mutex_lock(&philo->mutex[left_fork]) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	print_action(LEFT_FORK, philo, curr_philo + 1);
	if (pthread_mutex_lock(&philo->mutex[right_fork]) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	if (philo->death == 0)
		if (eating_action(curr_philo, philo) == -1)
			return (-1);
	if (pthread_mutex_unlock(&philo->mutex[left_fork]) != 0)
		return (error_msg(ERR_MUTEX_UNLOCK));
	if (pthread_mutex_unlock(&philo->mutex[right_fork]) != 0)
		return (error_msg(ERR_MUTEX_UNLOCK));
	return (0);
}
