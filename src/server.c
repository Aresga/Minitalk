/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:55 by agaga             #+#    #+#             */
/*   Updated: 2025/01/31 20:00:41 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <signal.h>
#include <stdio.h>

#define BUFFER_S 20000

void	sig_handler(int sig)
{
	static int				index;
	static unsigned char	c;
	static char				*buffer;
	static int				buffer_index;

	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_S);
		if (!buffer)
			exit(1);
		buffer_index = 0;
	}
	if (sig == SIGUSR1)
		c |= (1 << (7 - index));
	index++;
	if (index == 8)
	{
		buffer[buffer_index++] = c;
		if (buffer_index >= BUFFER_S - 1 || c == '\0')
		{
			buffer[buffer_index] = '\0';
			ft_printf("%s", buffer);
			free(buffer);
			buffer = (char *)malloc(BUFFER_S);
			if (!buffer)
				exit(1);
			buffer_index = 0;
		}
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
