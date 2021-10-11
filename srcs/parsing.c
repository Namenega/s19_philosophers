/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:47:32 by pyg               #+#    #+#             */
/*   Updated: 2021/10/11 18:23:50 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	parser_time_overview(t_philo *philo, char **av, int i)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		if (av[i][j] < '0' || av[i][j] > '9')
			return (1);
		j++;
	}
	if (j > 10)
		return (1);
	if (i == 2)
		philo->time_to_die = ft_atoi(av[i]);
	else if (i == 3)
		philo->time_to_eat = ft_atoi(av[i]);
	else if (i == 4)
		philo->time_to_sleep = ft_atoi(av[i]);
	return (0);
}

static int	parser_time(t_philo *philo, char **av)
{
	int	i;

	i = 2;
	while (i <= 4)
	{
		if (parser_time_overview(philo, av, i) == 1)
			return (1);
		i++;
	}
	if (philo->time_to_die < 1 || philo->time_to_eat < 1
		|| philo->time_to_sleep < 1)
		return (1);
	else if (philo->time_to_die > INT32_MAX || philo->time_to_eat > INT32_MAX
		|| philo->time_to_sleep > INT32_MAX)
		return (1);
	return (0);
}

static int	parser_must_eat(t_philo *philo, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	if (i > 10)
		return (1);
	philo->num_of_eat = ft_atoi(s);
	if (philo->num_of_eat < 1)
		return (1);
	else if (philo->num_of_eat > INT32_MAX)
		return (1);
	return (0);
}

static int	parser_nb_philo(t_philo *philo, char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
			return (1);
		i++;
	}
	if (i > 10)
		return (1);
	philo->num_philo = ft_atoi(av[1]);
	philo->num_forks = ft_atoi(av[1]);
	if (philo->num_philo < 1 || philo->num_forks < 1)
		return (1);
	else if (philo->num_philo > INT32_MAX || philo->num_forks > INT32_MAX)
		return (1);
	if (av[5])
		return (parser_must_eat(philo, av[5]));
	return (0);
}

int	parsing(t_philo *philo, char **av)
{
	if (parser_nb_philo(philo, av) == 1)
	{
		error_msg("Error: philo/forks/time_must_eat argument is wrong\n");
		return (1);
	}
	else if (parser_time(philo, av) == 1)
	{
		error_msg("Error: one in time arguments is wrong\n");
		return (1);
	}
	// printf("philo->num_philo = [%d] = [%s]\n", philo->num_philo, av[1]);
	// printf("philo->num_forks = [%d] = [%s]\n", philo->num_forks, av[1]);
	// printf("philo->time_to_die = [%d] = [%s]\n", philo->time_to_die, av[2]);
	// printf("philo->time_to_eat = [%d] = [%s]\n", philo->time_to_eat, av[3]);
	// printf("philo->time_to_sleep = [%d] = [%s]\n", philo->time_to_sleep, av[4]);
	// printf("philo->num_of_eat = [%d] = [%s]\n", philo->num_of_eat, av[5]);
	return (0);
}
