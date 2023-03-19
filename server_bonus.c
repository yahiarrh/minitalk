/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:17 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/03/19 13:16:37 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

static void	handler(int signal, siginfo_t *info, void *s)
{
	static pid_t	client_pid;
	static char		c;
	static int		i;

	(void)s;
	if (client_pid != info->si_pid || !client_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		c = (c | 1);
	i++;
	if (i == 8)
	{
		check(c, client_pid);
		i = ft_putchar(c);
		c = 0;
	}
	else
		c = c << 1;
}

void	check(char c, pid_t client_pid)
{
	if (c == 0)
	{
		kill(client_pid, SIGUSR1);
		return ;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("%sWrong parameters try : %s\n[./server]\n",
			COLOR_RED, COLOR_GREEN);
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%sPID : %d \n", COLOR_BLUE, getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
