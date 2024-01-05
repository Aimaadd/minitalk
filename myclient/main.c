/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:58:18 by abentaye          #+#    #+#             */
/*   Updated: 2024/01/05 12:02:10 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	count;

	count = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (ft_isdigit(*str))
	{
		count = (count * 10) + (*str - '0');
		str++;
	}
	return (count * sign);
}

void	ft_error(void)
{
	printf("error\n");
}

void	pid_checker(int pid)
{
	if (pid < 0 || !ft_isdigit(pid))
		ft_error();
}

int	parameters_handler(int args, char *string)
{
	if (args != 3)
	{
		ft_error();
		return (0);
	}
	if (string[0] != '\0')
		printf("ok ok \n");
	return (1);
}


int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (parameters_handler(argc, argv[2]) == 1)
		pid_checker(pid);
	else 
		ft_error();
	return (1);
}
