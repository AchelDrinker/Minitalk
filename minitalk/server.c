/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:26:28 by humartin          #+#    #+#             */
/*   Updated: 2022/08/29 09:53:47 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig)
{
	static char	str = 0;
	static int	get_byte = 0;

	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		if (!str)
			ft_putstr_fd("\n", 1);
		ft_putstr_fd(&str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_putstr_fd(GREEN "PID => " RESET, 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	while (1)
	{
		pause();
	}
	return (0);
}
