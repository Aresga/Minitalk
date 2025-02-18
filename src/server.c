/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:55 by agaga             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/07 17:19:38 by agaga            ###   ########.fr       */
=======
/*   Updated: 2025/02/18 13:54:58 by agaga            ###   ########.fr       */
>>>>>>> b779aa6 (	modified:   src/server.c)
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <signal.h>
#include <unistd.h>

void	sig_handler(int sig)
{
	static int				index = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c = c | (1 << (7 - index));
	index++;
	if (index == 8)
	{
		write (1, &c, 1);
		index = 0;
		c = 0;
	}
}

// int	main(void)
// {
// 	ft_printf("Server PID: %d\n", getpid());
// 	signal(SIGUSR1, sig_handler);
// 	signal(SIGUSR2, sig_handler);
// 	while (1)
// 	{
// 		pause();
// 	}
// 	return (0);
// }

int	main(void)
{
    struct sigaction	sa;

    ft_printf("Server PID: %d\n", getpid());
    
    // Initialize sigaction struct
    sa.sa_handler = sig_handler;
    sa.sa_flags = SA_RESTART;  // Automatically restart interrupted system calls
    sigemptyset(&sa.sa_mask);  // Initialize empty signal mask
    
    // Set up signal handlers
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("Error setting up SIGUSR1 handler\n");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error setting up SIGUSR2 handler\n");
        exit(EXIT_FAILURE);
    }
    
    while (1)
    {
        pause();
    }
    return (0);
}