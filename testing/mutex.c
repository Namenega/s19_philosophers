/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:06:10 by namenega          #+#    #+#             */
/*   Updated: 2021/10/11 16:29:27 by namenega         ###   ########.fr       */
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
	for (int i = 0; i < 100000000; i++)
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
	pthread_t	t1;
	pthread_t	t2;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	pthread_mutex_destroy(&mutex);
	printf("Nbr of mails : [%d]\n", mails);
	return (0);
}
