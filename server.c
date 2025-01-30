/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:55 by agaga             #+#    #+#             */
/*   Updated: 2025/01/30 16:26:01 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include <signal.h>

void	sig_handler(int sig)
{
	static int				index;
	static unsigned char	c;

	c = c | (sig == SIGUSR1);
	index++;
	if (index == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		index = 0;
		c = 0;
	}
	else
		c <<= 1;
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
