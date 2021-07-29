
//TODO

//? NORM
//? LEAKS
//? NO LIBFT

//! if sleep 	- not eat	not think
//! if eat		- not sleep	not think
//! if think	- not sleep	not eat

//! two forks each

//! philo can't starve
//! philo needs to eat
//! philo dont speak to each other (no interaction)
//! philo dont know when one dies

//! philo finishes eating -> drops forks -> sleeps
//! philo sleeps -> wakes up -> thinks

//! simulation ends when a philo dies

//! OPTIONS for each program
//* Parsing

//  number_of_philosophers						= number of philo && number of forks

//  time_to_die									= in milliseconds
//												= if don't start eating -> from start of last meal
//												= or beginning of simulation

//  time_to_eat									= in milliseconds
//												= time it takes to eat
//												= need to keep the two forks

//  time_to_sleep								= in milliseconds
//												= time to sleep

//  number_of_time_each_philosopher_must_eat	= (optional)
//												= if philo eat at least x number of time
//												= simulation stops
//												= if not, stops when philo dies

//! each philo have a number from 1 to "number_of_philosophers"
//! philo 1 is next to philo "number_of_philosophers", the rest is between them, in order

//! any changes of status of a philo must be written as follows

// timestamp_in_ms	X(number_of_philo)	has taken the fork
// timestamp_in_ms	X(number_of_philo)	is eating
// timestamp_in_ms	X(number_of_philo)	is sleeping
// timestamp_in_ms	X(number_of_philo)	is thinking
// timestamp_in_ms	X(number_of_philo)	died

//! status must be in right order

//! can't have more than 10ms between the death and the printing of the death.
//! philo should avoid dying lol


//? MAN MEMSET
/*
** #include <string.h>
** void *memset(void *s, int c, size_t n);
**
** Remplit
** les 'n' premiers octets
** de la zone mémoire pointée par 's'
** avec l'octet 'c'
**
** return un pointeur sur la zone mémoire 'c'
*/


//? MAN USLEEP
/*
** #include <unistd.h>
** int	usleep(useconds_t usec);
**
** Suspend l'exécution d'un programme
** durant 'usec' microsecondes
** 
** return 0 ou -1 (erreur)
*/


//? MAN GETTIMEOFDAY
/*
** #include <sys/time.h>
** int	gettimeofday(struct timeval *tv, struct timezone *ts);
**
** Lire ou programmer l'heure
** 'tz' = NULL
** return 0 ou -1 (erreur)
*/


//? MAN PTHREAD_CREATE
/*
** #include <pthread.h>
** int	pthread_create(pthread_t *thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg);
**
** Crée un nouveau thread s'exécutant simultanément avec le thread appelant
** Nouveau thread exécute la fonction 'start routine' en lui passant 'arg' comme premier argument
** 
** S'arrête avec pthread_exit ou quand 'start_routine' s'achève.
** 
** 'attr' indique les attributs du nouveau thread (peut etre  = NULL)
** 
** return 0 et id du nouveau thread est pointé par l'argument 'thread'
** return != 0 en cas d'erreur.
*/


//? MAN PTHREAD_DETACH
/*
** #include <pthread.h>
** int pthread_detach(pthread_t th);
**
** Place le thread 'th' en état 'détaché' (?)
** -> Garantit que les ressources mémoires consommées par 'th' seront
** immédiatement libérées lorsque l'execution de 'th' s'achèvera.
** 
** !! : Empeche les autres threads de se synchroniser sur la mort de 'th' en utilisant 'pthread_join'
** 
** pthread_detach ne s'applique qu'aux threads créés dans l'état 'joignable' (?)
** 
** return 0
** return != 0 en cas d'erreur.
*/


//? MAN PTHREAD_JOIN
/*
** #include <pthread.h>
** int pthread_join(pthread_t th, void **thread_return);
** 
** Suspend l'exécution du thread appelant, jusqu'à ce que le thread identifié par 'th' achève son execution
** 
** Si 'thread_return' ne vaut pas NULL, la valeur renvoyée par 'th' y sera stockée
** 
** le thread rejoint 'th', doit etre danas l'etat 'joignable'
** et pas détaché par pthread_detach.
** 
** 
** 
** 
** succes : valeur renvoyée par 'th' est enregistrée à l'emplacement pointé par 'thread_return
** succes : return 0
** return != 0 en cas d'erreur.
*/


//? MAN PTHREAD_MUTEX_INIT
/*
** #include <pthread.h>
** int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
** 
** mutex = MUtual EXclusion -> pratique pour protéger des données partagées
** mutex peut être déverrouillé (pris par aucun thread)
** mutex peut être verrouillé (appartenant à un thread)
** mutex pris que par un seul thread à la fois
** un thread qui tente de verrouiller un mutex deja verrouillé, est suspendu jusqu'au déverrouillage
** 
** Iinitialise le mutex pointé par 'mutex' selon les attributs de mutex spécifié par 'mutexattr'
** 
** 
** 
** 
** 
** return tjs 0
** return != 0 en cas d'erreur.
*/





