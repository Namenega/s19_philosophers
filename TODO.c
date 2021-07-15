
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
