/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:59:46 by pyg               #+#    #+#             */
/*   Updated: 2021/10/14 17:02:23 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
	return (-1);
}

static void	free_philo(t_philo *philo)
{
	free(philo->philo_id);
	free(philo->nb_meals);
	free(philo->actual_time);
	free(philo->meals);
	free(philo->philo);
	free(philo->mutex);
}

static void	initiate_struct(t_philo *ph)
{
	ph->num_philo = 0;
	ph->left_fork = 0;
	ph->right_fork = 0;
	ph->time_to_die = 0;
	ph->time_to_eat = 0;
	ph->time_to_sleep = 0;
	ph->num_of_eat = 0;
	ph->death = 0;
	ph->philo_id = NULL;
	ph->nb_meals = NULL;
	ph->meals = NULL;
	ph->start_time = 0;
}

int main(int ac, char **av)
{
	t_philo	*philo;

	philo = get_struct();
	initiate_struct(philo);
	if (ac != 5 && ac != 6)
		return(error_msg("ERROR: wrong number of ARGS"));
	if (parser_arg(ac, av, philo) == -1)
		return (-1);
	if (get_philo_id(philo) == -1)
		return (-1);
	if (start(philo) == -1)
		return (-1);
	free_philo(philo);
	return (0);
}
