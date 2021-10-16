/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:35:30 by pyg               #+#    #+#             */
/*   Updated: 2021/10/16 19:01:03 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					j;
	unsigned long int	result;

	i = 0;
	j = 0;
	result = 0;
	while (nptr[j] != '\0')
	{
		if (nptr[j] < '0' || nptr[j] > '9')
			return (0);
		j++;
	}
	if (j > 10)
		return (error_msg("Error: argument can't be bigger than 2147483647."));
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (result > INT32_MAX)
		return (error_msg("Error: argument can't be bigger than 2147483647."));
	return (result);
}

int	print_action(char *s, t_philo *philo, int curr_philo)
{
	if (pthread_mutex_lock(&philo->write_mutex) != 0)
		return (error_msg(ERR_MUTEX_LOCK));
	printf("%ld philo_%d %s", what_time(philo), curr_philo, s);
	if (pthread_mutex_unlock(&philo->write_mutex) != 0)
		return (error_msg(ERR_MUTEX_UNLOCK));
	return (0);
}

t_philo	*get_struct(void)
{
	static t_philo	ph;

	return (&ph);
}
