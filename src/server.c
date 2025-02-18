/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:47:55 by agaga             #+#    #+#             */
/*   Updated: 2025/02/18 14:34:01 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <signal.h>
#include <unistd.h>

void    sig_handler(int sig, siginfo_t *info, void *context)
{
    static int              index = 0;
    static unsigned char    c = 0;
    pid_t                   client_pid;

    (void)context;
    client_pid = info->si_pid;

    if (sig == SIGUSR1)
        c |= (1 << (7 - index));
    index++;

    // Send confirmation signal
    kill(client_pid, SIGUSR1);

    if (index == 8)
    {
        write(1, &c, 1);
        index = 0;
        c = 0;
    }
}

// void	sig_handler(int sig)
// {
// 	static int				index = 0;
// 	static unsigned char	c = 0;

// 	if (sig == SIGUSR1)
// 		c = c | (1 << (7 - index));
// 	index++;
// 	if (index == 8)
// 	{
// 		if (c == '\0')
// 			write (1, "\n", 1);
// 		else
// 			write (1, &c, 1);
// 		index = 0;
// 		c = 0;
// 	}
// }

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

int    main(void)
{
    struct sigaction    sa;

    ft_printf("Server PID: %d\n", getpid());
    
    sa.sa_sigaction = sig_handler;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
        sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error setting up signal handlers\n");
        exit(EXIT_FAILURE);
    }
    
    while (1)
        pause();
    return (0);
}