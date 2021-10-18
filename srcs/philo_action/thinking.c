/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:00:50 by namenega          #+#    #+#             */
/*   Updated: 2021/10/18 23:18:47 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/****************************** Thinking process ******************************/

int	thinking(int curr_philo, t_philo *philo)
{
	if (philo->death == 0)
		if (print_action(THINK, philo, curr_philo + 1) == -1)
			return (-1);
	return (0);
}
