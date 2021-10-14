/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:47:32 by pyg               #+#    #+#             */
/*   Updated: 2021/10/14 17:11:24 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	parser_data(char **av, t_philo *data)
{
	data->num_philo = ft_atoi(av[1]);
	if (data->num_philo < 1)
		return (-1);
	data->time_to_die = ft_atoi(av[2]);
	if (data->time_to_die <= 0)
		return (-1);
	data->time_to_eat = ft_atoi(av[3]);
	if (data->time_to_eat <= 0)
		return (-1);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_sleep <= 0)
		return (-1);
	if (av[5])
		data->num_of_eat = ft_atoi(av[5]);
	else
		data->num_of_eat = 0;
	return (0);

}

int	parser_arg(int ac, char **av, t_philo *ph)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (is_digit(av[i]) == -1)
			return (error_msg("Error: mistake in arguments."));
	if (parser_data(av, ph) == -1)
		return (-1);
	return (0);
}
