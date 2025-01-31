/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:44:13 by agaga             #+#    #+#             */
/*   Updated: 2025/01/31 23:49:39 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	seg_send(int pid, unsigned char c)
{
	int	index;

	index = 8;
	while (index > 0)
	{
		index--;
		if ((c >> index) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error sending SIGUSR1\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending SIGUSR2\n");
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	char		*msg;
	int			server_pid;
	size_t		index;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid < 1)
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	msg = av[2];
	index = 0;
	while (msg[index])
	{
		seg_send(server_pid, msg[index]);
		index++;
	}
	seg_send(server_pid, '\0');
	return (0);
}
