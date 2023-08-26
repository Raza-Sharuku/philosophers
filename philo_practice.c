/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_practice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:11:24 by razasharuku       #+#    #+#             */
/*   Updated: 2023/08/26 11:16:26 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

// int	argc_error(void)
// {
// 	printf("USAGE: ./philo Number_of_philosophers Time_to_die Time_to_eat \
// 	Time_to_sleep [ Number_of_times_each_philosopher_must_eat ] \n");
// 	return (1);
// }

// t_philo *get_philo_values(char **argv)
// {
// 	t_philo *philo;
// }

// int main(int argc, char **argv)
// {
// 	struct timeval *tv;
// 	t_philo *philo;

// 	if (argc != 5 && argc != 6)
// 		return (argc_error());
// 	philo = get_philo_values(argv);
// 	gettimeofday(tv, NULL);
// 	printf("%ld %06d\n", tv->tv_sec, tv->tv_usec);
// 	return (0);
// }
pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;

// void *thread_func(void *arg)
// {
// 	int id;
// 	int i;
// 	struct timeval tv;
	

// 	id = (int)arg;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		gettimeofday(&tv, NULL);
// 		printf("%06d : id = %d, i = %d\n", tv.tv_usec, id , i);
// 		sleep(1);
// 		i++;
// 	}
// 	return "finished!";
// }

void some_func(void *arg)
{
	int i;

	i = 0;
	if (pthread_mutex_lock(&mux) != 0)
	{
		perror("pthread_mutex_lock");
		exit(-1);
	}
	while (i++ < 5)
		printf("i = %i\n", i);
	if (pthread_mutex_unlock(&mux) != 0)
	{
		perror("pthread_mutex_unlock");
		exit(-1);
	}
	return ;
}

int main(int argc, char **argv)
{
	pthread_t th1;
	pthread_t th2;

	// スレッドの生成
	if (pthread_create(&th1, NULL, some_func, NULL) != 0)
	{
		perror("pthread_create");
		return (-1);
	}
	if (pthread_create(&th2, NULL, some_func, NULL) != 0)
	{
		perror("pthread_create");
		return (-1);
	}

	// スレッドの待機
	if (pthread_join(th1, NULL) != 0)
	{
		perror("pthread_join");
		return (-1);
	}
	if (pthread_join(th2, NULL) != 0)
	{
		perror("pthread_join");
		return (-1);
	}

	// ミューテックスオブジェクトの解放
	if (pthread_mutex_destroy(&mux) != 0)
	{
		perror("pthread_mutex_destroy");
		return (-1);
	}
	return (0);
	
}

// int main(int argc, char **argv)
// {
// 	pthread_attr_t	attr;
// 	pthread_t		th;

// 	if (pthread_attr_init(&attr) != 0)
// 	{
// 		perror("pthread_attr_init");
// 		return (-1);
// 	}
// 	if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0)
// 	{
// 		perror("pthread_attr_setdetachstate");
// 		return (-1);
// 	}
// 	if (pthread_create(&th, &attr, thread_func, NULL) != 0)
// 	{
// 			perror("pthread_create");
// 			return (-1);
// 	}
// 	if (pthread_attr_destroy(&attr) != 0)
// 	{
// 			perror("pthread_attr_destroy");
// 			return (-1);
// 	}
// 	sleep(7);
// 	return (0);
// }

// int main(int argc, char **argv)
// {
// 	pthread_t v[NUM_THREADS];
// 	int i;
// 	char *ptr;
	
// 	i = 0;
// 	while (i < NUM_THREADS)
// 	{
// 		if (pthread_create(&v[i], NULL, thread_func, (void *)i) != 0)
// 		{
// 			perror("pthread_create");
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < NUM_THREADS)
// 	{
// 		if (pthread_join(v[i], (void **)&ptr) == 0)
// 			printf("msg = %s\n", ptr);
// 		else 
// 		{
// 			perror("pthread_create");
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }