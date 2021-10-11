/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:57:49 by namenega          #+#    #+#             */
/*   Updated: 2021/10/11 15:20:07 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
pthread_mutex_t mutex;

void	*routine(void *arg)
{
	pthread_mutex_lock(&mutex);
	int	index = *(int *)arg;
	printf("%d\n", primes[index]);
	free(arg);
	pthread_mutex_unlock(&mutex);
	return ((void *)&primes[index]);
}

int main(void)
{
	pthread_t	th[10];
	int i = 0;

	pthread_mutex_init(&mutex, NULL);
	while (i < 10)
	{
		int	*a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}