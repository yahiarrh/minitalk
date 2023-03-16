/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:31:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/03/16 18:49:38 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	return (r * s);
}

static void	send_message(int pi, char *str)
{
	char	c;
	int		i;
	int		f = 0;

	while (str[f])
	{
		i = 7;
		c = str[f];
		while (i>=0)
		{
			if (1 & (c >> i))
				kill(pi, SIGUSR1);
			else
				kill(pi, SIGUSR2);
			usleep(700);
			i--;
		}
		f++;
	}
}

int	main(int ac, char **av)
{
	int	pi;

	pi = 0;
	if(ac != 3 || pi < 0)
	{
		ft_printf("Wrong parameters try : \n[./client] [Server PID] [Message]\n");
        exit(EXIT_FAILURE);
	}
	pi = ft_atoi(av[1]);
	send_message(pi, av[2]);
}
