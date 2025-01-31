/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:55 by agaga             #+#    #+#             */
/*   Updated: 2025/01/31 23:39:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <signal.h>
#include <unistd.h>

void	sig_handler(int sig)
{
	static int				index;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c |= (1 << (7 - index));
	index++;
	if (index == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			write (1, &c, 1);
		index = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
