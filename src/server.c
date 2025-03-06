/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:55 by agaga             #+#    #+#             */
/*   Updated: 2025/02/27 20:30:35 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int				index;
	static unsigned char	c;
	static int				client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << (7 - index));
	index++;
	if (index == 8)
	{
		if (c == '\0')
			kill(client_pid, SIGUSR2);
		write(1, &c, 1);
		index = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_error_handler(ERR_EMPTYSET);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_handler(ERR_SIG);
	while (1)
		pause();
	return (0);
}
