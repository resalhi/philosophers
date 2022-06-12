# philosophers
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.


the program  should take the following arguments:
number_of_philosophers, time_to_die, time_to_eat, time_to_sleep,
[number_of_times_each_philosopher_must_eat].


◦ number_of_philosophers: The number of philosophers and also the number
of forks.


◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.


◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.


◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.


◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

here is an example :

run make it will compile and add philo
excute as follow: ./philo 5 800 200 200

5 is the number of philosophers
800 is time to die in (ms), if the philosopher didn't eat for 800 ms he will die.


200 is time to eat in (ms), the time it takes to eat for the philosopher.


200 is time to sleep in (ms), the time it tekes to sleep for the philosopher.


The program of the bonus part takes the same arguments as the mandatory program, the only difference between philo and philo_bonus is that in philo Each philosopher should be a thread, and in philo_bonus Each philosopher should be a process.

