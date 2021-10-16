/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:33:05 by namenega          #+#    #+#             */
/*   Updated: 2021/10/16 14:20:17 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/************************ Initiate Mutex filled with 0 ************************/

static int	initiate_mutex(t_philo *t)
{
	int	i;

	i = -1;
	t->philo = malloc(sizeof(pthread_t) * t->num_philo);
	if (!t->philo)
		return (error_msg(ERR_MALLOC));
	memset(t->philo, 0, t->num_philo * 8);
	t->mutex = malloc(sizeof(pthread_mutex_t) * t->num_philo);
	if (!t->mutex)
		return (error_msg(ERR_MALLOC));
	memset(t->mutex, 0, t->num_philo * 8);
	while (++i < t->num_philo)
	{
		if (pthread_mutex_init(&t->mutex[i], NULL) != 0)
			return (error_msg(ERR_MUTEX_INIT));
	}
	if (pthread_mutex_init(&t->write_mutex, NULL) != 0
		|| pthread_mutex_init(&t->dead_mutex, NULL) != 0)
		return (error_msg(ERR_MUTEX_INIT));
	return (0);
}

static int	get_id_next(t_philo *ph_id, int i)
{
	i = -1;
	ph_id->actual_time = malloc(sizeof(long int) * ph_id->num_philo);
	if (!ph_id->actual_time)
		return (error_msg(ERR_MALLOC));
	while (++i < ph_id->num_philo)
		ph_id->actual_time[i] = 0;
	ph_id->nb_meals = malloc(sizeof(int) * ph_id->num_philo);
	if (!ph_id->nb_meals)
		return (error_msg(ERR_MALLOC));
	i = -1;
	while (++i < ph_id->num_philo)
		ph_id->nb_meals[i] = 0;
	return (0);
}

static int	get_id(t_philo *ph_id)
{
	int	i;

	i = -1;
	ph_id->philo_id = malloc(sizeof(int) * ph_id->num_philo);
	if (!ph_id->philo_id)
		return (error_msg(ERR_MALLOC));
	while (++i < ph_id->num_philo)
		ph_id->philo_id[i] = i;
	ph_id->meals = malloc(sizeof(int) * ph_id->num_philo);
	if (!ph_id->meals)
		return (error_msg(ERR_MALLOC));
	i = -1;
	while (++i < ph_id->num_philo)
		ph_id->meals[i] = 0;
	return (get_id_next(ph_id, i));
}

/********************** Get info about each philosopher ***********************/

int	get_philo_id(t_philo *philo)
{
	if (get_id(philo) == -1)
		return (-1);
	if (initiate_mutex(philo) == -1)
		return (-1);
	return (0);
}
