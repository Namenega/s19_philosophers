/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:15:49 by namenega          #+#    #+#             */
/*   Updated: 2021/10/11 18:35:56 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	what_time(t_philo *ph)
{
	struct timeval	tv;
	long int		ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000;
	ms += tv.tv_usec / 1000;
	return (ms - ph->start_time);
}

void	*routine(void *a)
{
	int	i;
	t_philo *ph;

	ph = get_struct();
	i = *(int*)a;
	free(a);
	return (NULL);
}

int	philo(t_philo *ph)
{
	int	i;
	int	*a;

	i = 0;
	ph->philo = malloc(sizeof(pthread_t) * ph->num_philo);
	while (i < ph->num_philo)
	{
		a = malloc(sizeof(int));
		*a = i;
		printf("test [%d]\n", i);
		if (pthread_create(&ph->philo[i], NULL, &routine, a) != 0)
		{
			error_msg("ERROR: fail to _create threads");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < ph->num_philo)
	{
		if (pthread_join(ph->philo[i], NULL) != 0)
		{
			error_msg("ERROR: fail to _join threads");
			return (-1);
		}
		i++;
	}
	return (1);
}