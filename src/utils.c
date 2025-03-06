/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:33 by agaga             #+#    #+#             */
/*   Updated: 2025/02/27 20:28:54 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_handler(t_error error_type)
{
	ft_putstr_fd(RED"ERROR! \n"CL, 2);
	if (error_type == ERR_ARG)
		ft_putstr_fd(CYAN"Usage: ./client <PID> <MESSAGE>\n"CL, 2);
	if (error_type == ERR_SIG)
		ft_putstr_fd(CYAN"Error Setting Up Signal Handler\n"CL, 2);
	if (error_type == ERR_PID)
		ft_putstr_fd(CYAN"Invalid PID - Contains Invalid Characters\n"CL, 2);
	if (error_type == ERR_NOPID)
		ft_putstr_fd(CYAN"PID Does Not Exist\n"CL, 2);
	if (error_type == ERR_TIMEOUT)
		ft_putstr_fd(CYAN"TIMEOUT - Server Didn't Respond\n"CL, 2);
	if (error_type == ERR_EMPTYSET)
		ft_putstr_fd(CYAN"Error Empty Set\n"CL, 2);
	exit(EXIT_FAILURE);
}

void	check_pid(char *pid)
{
	int	index;

	index = 0;
	while (pid[index])
	{
		if (!ft_isdigit(pid[index]))
			ft_error_handler(ERR_PID);
		index++;
	}
	return ;
}

void	pid_exist(int pid)
{
	if (kill(pid, 0) == 0)
		return ;
	if (errno == ESRCH)
		ft_error_handler(ERR_NOPID);
}

void	check(int pid, char *av)
{
	check_pid(av);
	pid_exist(pid);
}
