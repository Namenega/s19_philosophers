/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:35:30 by pyg               #+#    #+#             */
/*   Updated: 2021/07/15 18:18:38 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t size)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;

	while (i < size)
	{
		str[i] = '\0';
		i++;
	} 
}

void	*ft_calloc(size_t size)
{
	void	*tab;

	tab = malloc(size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}

// static int	norminette_v3(unsigned long int result, int compteur)
// {
// 	if (result > 2147483648)
// 	{
// 		if (compteur == -1)
// 			return (0);
// 		else
// 			return (-1);
// 	}
// 	return (compteur);
// }

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
		if (nptr[j] < 48 || nptr[j] > 57)
			return (0);
		j++;
	}
	// while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\f'
	// 	|| nptr[i] == '\r' || nptr[i] == ' ' || nptr[i] == '\v')
	// 	i++;
	// if (nptr[i] == '-' || nptr[i] == '+')
	// {
	// 	if (nptr[i] == '-')
	// 		compteur *= -1;
	// 	i++;
	// }
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	// compteur = norminette_v3(result, compteur);
	return (result);
}