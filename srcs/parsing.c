/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:47:32 by pyg               #+#    #+#             */
/*   Updated: 2021/07/15 18:53:23 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	parse_time_values(t_philo *ph, char **av)
{
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	if (ph->time_to_die < 10 || ph->time_to_eat < 10 || ph->time_to_sleep < 10)
	{
		error_msg("ERROR: 'time' ARGS should be >= 10 milliseconds.\n");
		return (0);
	}
	return (1);
}

static int	check_num_values(t_philo *philo, char **av)
{
	philo->num_philo = ft_atoi(av[1]);
	if (philo->num_philo > 200 || philo->num_philo < 2)
	{
		error_msg("ERROR: 1st ARG must be a number between 2 & 200.\n");
		return (0);
	}
	philo->num_forks = ft_atoi(av[1]);
	if (av[5])
	{
		philo->num_of_eat = ft_atoi(av[5]);
		if (philo->num_of_eat < 1)
		{
			error_msg("ERROR: philo should eat at least 1 time.\n");
			return (0);
		}
	}
	return (1);
}

int	parsing(t_philo *philo, char **av)
{
	if (check_num_values(philo, av) == 0)
		return (0);
	if (parse_time_values(philo, av) == 0)
		return (0);
	// printf("philo->num_philo = [%d] = [%s]\n", philo->num_philo, av[1]);
	// printf("philo->num_forks = [%d] = [%s]\n", philo->num_forks, av[1]);
	// printf("philo->time_to_die = [%f] = [%s]\n", philo->time_to_die, av[2]);
	// printf("philo->time_to_eat = [%f] = [%s]\n", philo->time_to_eat, av[3]);
	// printf("philo->time_to_sleep = [%f] = [%s]\n", philo->time_to_sleep, av[4]);
	// printf("philo->num_of_eat = [%d] = [%s]\n", philo->num_of_eat, av[5]);
	return (1);
}
