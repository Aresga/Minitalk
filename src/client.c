/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:44:13 by agaga             #+#    #+#             */
/*   Updated: 2025/02/05 16:57:09 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Thi function sends a signal to the server
// The signal is either SIGUSR1 or SIGUSR2
// SIGUSR1 is sent if the bit is 1
// SIGUSR2 is sent if the bit is 0
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
		usleep(400);
	}
}

int	check_pid(char *pid)
{
	int	index;

	index = 0;
	while (pid[index])
	{
		if (!ft_isdigit(pid[index]))
			return (0);
		index++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char		*msg;
	int			server_pid;
	int			index;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	if (!check_pid(av[1]))
	{
		ft_printf("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
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
