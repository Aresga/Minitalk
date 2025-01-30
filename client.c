/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:44:13 by agaga             #+#    #+#             */
/*   Updated: 2025/01/30 16:16:35 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include <signal.h>
#include <stdlib.h>

void	seg_send(int pid, unsigned char c)
{
	unsigned char	temp;
	int				index;

	index = 8;
	temp = c;
	while (index > 0)
	{
		index--;
		temp = c >> index;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(30);
	}
}

int	main(int ac, char **av)
{
	const char	*msg;
	pid_t		server_pid;
	int			index;

	if (ac != 3)
	{
		ft_printf("Usage : %s <PID> <MESSAGE>\n", av[0]);
		exit(1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid < 1)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	msg = av[2];
	index = 0;
	while (msg[index] != '\0')
	{
		seg_send(server_pid, msg[index]);
		index++;
	}
	seg_send(server_pid, '\0');
	return (0);
}
