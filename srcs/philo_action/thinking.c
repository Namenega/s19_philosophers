/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:00:50 by namenega          #+#    #+#             */
/*   Updated: 2021/10/14 16:42:26 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	thinking(int curr_philo, t_philo *philo)
{
	if (philo->death == 0)
		print_action(THINK, philo, curr_philo + 1);
}
