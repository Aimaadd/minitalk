/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:29:18 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/06 15:09:41 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	server_pid(void)
{
	int	pid;

	pid = getpid();
	return (pid);
}

void	action(int sig)
{
	static char				c = 0;
	static unsigned int		i = 0;

	if (sig == SIGUSR2)
		c += 1 << i;
	if (++i == 8)
	{
		if (c == 0)
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		action(signum);
	}
	else if (signum == SIGUSR2)
	{
		action(signum);
	}
}

int	main(void)
{
	ft_printf("server pid : %d\n", server_pid());
	signal(SIGUSR2, signal_handler);
	signal(SIGUSR1, signal_handler);
	while (1)
		pause();
	return (0);
}
