/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:03:28 by pyg               #+#    #+#             */
/*   Updated: 2021/10/16 18:16:14 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_MALLOC			"Error: allocation failed.\n"
# define ERR_CREATE			"Error: pthread_create failed.\n"
# define ERR_DETACH			"Error: pthread_detach failed.\n"
# define ERR_MUTEX_INIT		"Error: mutex_init failed.\n"
# define ERR_MUTEX_DESTROY	"Error: mutex_destroy failed.\n"
# define ERR_MUTEX_LOCK		"Error: mutex_init failed.\n"
# define ERR_MUTEX_UNLOCK	"Error: mutex_init failed.\n"
# define DIED				"died.\n"
# define THINK				"is thinking.\n"
# define EAT				"is eating.\n"
# define LEFT_FORK			"has taken left fork.\n"
# define RIGHT_FORK			"has taken right fork.\n"
# define SLEEP				"is sleeping.\n"

typedef struct s_philo
{
	int				num_philo;
	int				left_fork;
	int				right_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	int				death;			//do_we_have_a_dead
	int				*philo_id;
	int				*nb_meals;		//ate_enough
	int				*meals;			//did_he_eat_enough
	long int		start_time;		//start_timer
	long int		*actual_time;	//when_did_he_eat
	pthread_t		*philo;			//thread
	pthread_t		thread_time;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead_mutex;
}				t_philo;

/*********************************** MAIN_C ***********************************/

int			main(int ac, char **av);
int			error_msg(char *s);

/********************************** PARSER_C **********************************/

int			parser_arg(int ac, char **av, t_philo *ph);

/********************************* PHILO_ID_C *********************************/

int			get_philo_id(t_philo *philo);

/********************************** PHILO_C ***********************************/

int			start(t_philo *philo);
void		*routine(void *philo);

/******************************* TIME_ROUTINE_C *******************************/

void		*time_routine(void *time_arg);
long int	what_time(t_philo *ph);

/********************************** EATING_C **********************************/

int			eating(int curr_philo, t_philo *philo, int left_fork, int right_fork);

/********************************* THINKING_C *********************************/

int			thinking(int curr_philo, t_philo *philo);

/********************************* SLEEPING_C *********************************/

int			sleeping(int curr_philo, t_philo *philo);

/********************************** UTILS_C ***********************************/

t_philo		*get_struct(void);
int			print_action(char *s, t_philo *philo, int curr_philo);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(char *s);
int			is_digit(char *s);

#endif
