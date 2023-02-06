/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:17 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/02/06 18:52:30 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handler (int signal, siginfo_t *pid, void *s)
{
	static char	c = 0;
	static int	i = 0;

	(void)pid;
	(void)s;
	c |= (signal == SIGUSR1);
	if (++i == 8)
	{
	 		
	}
	else
		c <<= i;
}

int main(int ac, char **av)
{
	struct sigaction sa;

	(void)av;
	sa.sa_sigaction = handler;
	if(ac != 1)
	{
		ft_printf("Wrong parameters try : \n[./server]");
	}
	ft_printf("PID : %d \n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return(0);
}