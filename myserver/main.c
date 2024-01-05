/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:41:39 by abentaye          #+#    #+#             */
/*   Updated: 2024/01/05 09:52:42 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	signal_num(int signum)
{
	if (signum == -1)
	{
		printf("There was an issue with PID\n");
		return (1);
	}
	else
		printf("PID = %d\n", signum);
	return (0);
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

	pid = getpid();
	if (pid == -1)
		return (1);
	signal_num(pid);
	return (1);
}
