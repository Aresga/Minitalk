/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:33 by agaga             #+#    #+#             */
/*   Updated: 2025/02/26 19:30:15 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_handler(t_error error_type)
{
	ft_putstr_fd("ERROR!\n", 2);
	if (error_type == ERR_ARG)
		ft_putstr_fd("Usage: ./client <PID> <MESSAGE>\n", 2);
	if (error_type == ERR_SIG)
		ft_putstr_fd("Error setting up signal handler\n", 2);
	if (error_type == ERR_PID)
		ft_putstr_fd("Invalid PID\n", 2);
	exit(EXIT_FAILURE);
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



