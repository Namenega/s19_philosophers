/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:00:15 by namenega          #+#    #+#             */
/*   Updated: 2021/10/17 22:24:08 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	sleeping(int curr_philo, t_philo *philo)
{
	int			i;
	long int	time_till_death;

	i = 0;
	if (philo->death == 0)
	{
		if (print_action(SLEEP, philo, curr_philo + 1) == -1)
			return (-1);
		time_till_death = what_time(philo);
		// printf("\ntime_right_now = %ld\n", time_till_death);
		// printf("sleep = %d\n\n", philo->time_to_sleep);
		while (i < (10 * philo->time_to_sleep))
		{
			i++;
			if (what_time(philo) - time_till_death >= philo->time_to_sleep)
				break ;
			usleep(100);
		}
	}
	return (0);
}
