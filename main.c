/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:41:39 by abentaye          #+#    #+#             */
/*   Updated: 2024/01/04 17:30:58 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	signal_num(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("signal recieve is SIGUSR1\n");
		return (0);
	}
	else
		printf("signal received isn't SIGUSR1\n");
		return (1);
}

// int	client(void)
// {
// 	int	client;

// 	client = SIGUSR1;
// 	// if client (
// }

int	main(void)
{
	int	pid;

	pid = SIGUSR1;
	signal_num(pid);
	printf("PID : %d", pid);
	return (1);
}
