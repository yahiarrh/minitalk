/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:31:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/03/18 08:38:35 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}	
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = (r * 10) + (str[i++] - '0');
	if ((str[i] < 48 || str[i] > 57) && str[i])
	{
		ft_printf("invalid pid");
		exit(1);
	}
	return (r * s);
}

static void	last_char(int pi, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (1 & (c >> i))
			kill(pi, SIGUSR1);
		else
			kill(pi, SIGUSR2);
		usleep(700);
		i--;
	}
}

static void	send_message(int pi, char *str)
{
	char	c;
	int		i;

	while (*str)
	{
		i = 7;
		c = *str;
		while (i >= 0)
		{
			if (1 & (c >> i))
				kill(pi, SIGUSR1);
			else
				kill(pi, SIGUSR2);
			usleep(700);
			i--;
		}
		str++;
	}
	c = *str;
	last_char(pi, c);
}

static void	myhundler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("message rah mcha\n");
}

int	main(int ac, char **av)
{
	int	pi;

	if (ft_atoi(av[1]) <= 0)
	{
		ft_printf("invalid PID");
		exit (1);
	}
	if (ac != 3)
	{
		ft_printf("Wrong parameters try : \n[./client] [Server PID] [Message]\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &myhundler);
	pi = ft_atoi(av[1]);
	send_message(pi, av[2]);
}
