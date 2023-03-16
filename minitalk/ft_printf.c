/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:21:55 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/01/28 22:23:41 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr(int n)
{
	long	nbr;
	int		num;

	num = 0;
	nbr = n;
	if (nbr < 0)
	{
		num += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		num += ft_putnbr(nbr / 10);
		num += ft_putnbr(nbr % 10);
	}
	else
	{
		nbr += 48;
		num += write(1, &nbr, 1);
	}
	return (num);
}

static int	if_conv(char s)
{
	char	*f;

	f = "sd%";
	while (*f)
	{
		if (s == *f)
			return (1);
		f++;
	}
	return (0);
}

static int	prt(va_list reg, const char *arg)
{
	int count;

	count = 0;
	if (*arg == 's')
		count += ft_putstr(va_arg(reg, char *));
	else if (*arg == 'd')
		count += ft_putnbr(va_arg(reg, int));
	return (count);
}

int	ft_printf(const char *arg, ...)
{
	va_list	reg;
	int		num;

	num = 0;
	va_start(reg, arg);
	if (!arg)
		return (0);
	while (*arg)
	{
		if (*arg == '%' && if_conv(*(arg + 1)))
		{	
			arg++;
			num += prt(reg, arg);
		}
		else if (*arg != '%')
			num += write(1, &*arg, 1);
		++arg;
	}
	va_end (reg);
	return (num);
}