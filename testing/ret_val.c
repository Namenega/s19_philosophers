/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:41:17 by namenega          #+#    #+#             */
/*   Updated: 2021/10/11 14:54:09 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void	*roll_dice()
{
	int	*result = malloc(sizeof(int));
	int value = (rand() % 6) + 1;
	*result = value;
	printf("res = %p\n", result);
	return ((void *)result);
}

int main(void)
{
	pthread_t	t1;
	int		*result;

	srand(time(NULL));
	// pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &roll_dice, NULL) != 0)
		return (1);
	if (pthread_join(t1, (void **)&result) != 0)
		return (1);
	// pthread_mutex_destroy(&mutex);
	printf(".res = %p\n", result);
	printf("Result : [%d]\n", *result);
	free(result);
	return (0);
}