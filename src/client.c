/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:44:13 by agaga             #+#    #+#             */
/*   Updated: 2025/02/27 20:23:37 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_handler(int sig)
{
	if (sig == SIGUSR1)
		g_received = 1;
	else if (sig == SIGUSR2)
		ft_putstr_fd(GREEN"Message Recieved By Server.\n"CL, 2);
}

void	seg_send(int pid, unsigned char c)
{
	int	index;
	int	wait_time;

	index = 8;
	while (index-- > 0)
	{
		g_received = 0;
		if ((c >> index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		wait_time = 0;
		while (!g_received)
		{
			usleep(100);
			wait_time += 100;
			if (wait_time > 3000000)
				ft_printf(RED"\rWaiting: %d Seconds"CL, (wait_time / 1000000));
			if (wait_time >= 5000000)
			{
				ft_putchar('\n');
				ft_error_handler(ERR_TIMEOUT);
			}
		}
	}	
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					server_pid;
	int					index;

	if (ac != 3)
		ft_error_handler(ERR_ARG);
	sa.sa_handler = confirm_handler;
	sa.sa_flags = SA_RESTART;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_error_handler(ERR_EMPTYSET);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_handler(ERR_SIG);
	server_pid = ft_atoi(av[1]);
	check(server_pid, av[1]);
	index = 0;
	while (av[2][index])
	{
		seg_send(server_pid, av[2][index]);
		index++;
	}
	seg_send(server_pid, '\0');
	return (0);
}
