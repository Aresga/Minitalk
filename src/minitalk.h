/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:26:28 by agaga             #+#    #+#             */
/*   Updated: 2025/02/27 18:33:21 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <errno.h>

# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define CL "\033[0m"

typedef enum e_error
{
	ERR_ARG,
	ERR_SIG,
	ERR_PID,
	ERR_NOPID,
	ERR_TIMEOUT,
	ERR_EMPTYSET,
}	t_error;

static volatile sig_atomic_t	g_received = 0;

void	ft_error_handler(t_error error_type);
void	check(int pid, char *av);

#endif