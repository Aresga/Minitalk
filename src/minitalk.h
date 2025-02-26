/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:26:28 by agaga             #+#    #+#             */
/*   Updated: 2025/02/26 19:52:38 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_error
{
	ERR_ARG,
	ERR_SIG,
	ERR_PID,
}	t_error;

static volatile sig_atomic_t	g_received = 0;
static pid_t					client_pid = 0;

void	ft_error_handler(t_error error_type);
int		check_pid(char *pid);

#endif