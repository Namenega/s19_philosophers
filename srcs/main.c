/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:59:46 by pyg               #+#    #+#             */
/*   Updated: 2021/07/15 18:50:37 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
}

int main(int ac, char **av)
{
	t_philo	*ph;

	(void)av;
	ph = ft_calloc(sizeof(t_philo));
	if (ac != 5 && ac != 6)
		error_msg("ERROR: wrong number of ARGS");
	parsing(ph, av);
	return (0);
}
