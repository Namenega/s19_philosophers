/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:59:46 by pyg               #+#    #+#             */
/*   Updated: 2021/10/11 18:36:15 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	free_philo(t_philo *ph)
// {
// 	while (ph->p)
// }

void	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
}

int main(int ac, char **av)
{
	t_philo	*ph;

	ph = get_struct();
	if (ac != 5 && ac != 6)
	{
		error_msg("ERROR: wrong number of ARGS");
		return (0);
	}
	if (parsing(ph, av) == 1)
		return (0);
	ph->start_time = what_time(ph);
	// printf("start_time = [%ld]\n", ph->start_time);
	if (philo(ph) == -1)
		return (-1);
	//system("leaks philo");
	return (0);
}
