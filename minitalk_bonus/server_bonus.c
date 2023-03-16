/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:17 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/03/16 19:10:31 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
static void handler (int signal, siginfo_t *info, void *s)
{
	static char	c;
	static int	i;
	static pid_t	client_pid;

	(void)s; 
	if (!client_pid)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
	{
		c = (c | 1);
		i++;
	}
	else
		i++;
	if (i == 8)
	{
		if (c == 0)
		{
			kill(client_pid, SIGUSR1);
			return ;
		}
	 	ft_putchar(c);
		i = 0;
		c = 0;
	}
	else
		c = c << 1;
}

int main(int ac, char **av)
{
	struct sigaction sa;

	(void)av;
	if(ac != 1)
	{
		ft_printf("Wrong parameters try : \n[./server]");
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d \n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return(0);
}
