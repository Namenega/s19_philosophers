/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:29:13 by namenega          #+#    #+#             */
/*   Updated: 2021/10/11 14:40:30 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		// if (lock == 1)
			//wait until the lock is 0
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main(void)
{
	pthread_t	th[8];
	int	i = 0;

	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			return (1);
		printf("thread [%d] has started\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
		printf("thread [%d] has terminated\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Nbr of mails : [%d]\n", mails);
	return (0);
}