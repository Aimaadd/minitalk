/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:35:22 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/06 15:27:20 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	args_handler(int args, char *string)
{
	if (args != 3)
	{
		ft_printf("enter <PID> and your <message>\n");
		return (0);
	}
	if (ft_isdigit(*string) == 1)
		return (1);
	ft_printf("Wrong PID\n");
	return (0);
}

int	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
		++i;
	}
	return (0);
}

int	send_msg(char *msg, int pid)
{
	int	ret;

	while (*msg)
	{
		ret = send_char(*msg, pid);
		if (ret)
		{
			ft_printf("error\n");
			return (0);
		}
		++msg;
	}
	ret = send_char(0, pid);
	if (ret)
	{
		ft_printf("error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (args_handler(argc, argv[1]) == 1)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Sending message\n");
	}
	else
		return (0);
	send_msg(argv[2], pid);
	return (1);
}
