/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:44:13 by agaga             #+#    #+#             */
/*   Updated: 2025/02/18 14:34:33 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/inc/libft.h"
// #include <signal.h>
// #include <stdlib.h>
// #include <unistd.h>

// // Thi function sends a signal to the server
// // The signal is either SIGUSR1 or SIGUSR2
// // SIGUSR1 is sent if the bit is 1
// // SIGUSR2 is sent if the bit is 0
// void	seg_send(int pid, unsigned char c)
// {
// 	int	index;

// 	index = 8;
// 	while (index-- > 0)
// 	{
// 		if ((c >> index) & 1)
// 			kill(pid, SIGUSR1);
// 		else 
// 			kill(pid, SIGUSR2);
// 		usleep(800);
// 	}
// }

// int	check_pid(char *pid)
// {
// 	int	index;

// 	index = 0;
// 	while (pid[index])
// 	{
// 		if (!ft_isdigit(pid[index]))
// 			return (0);
// 		index++;
// 	}
// 	return (1);
// }

// int	main(int ac, char **av)
// {
// 	int			server_pid;
// 	int			index;

// 	if (ac != 3)
// 	{
// 		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!check_pid(av[1]))
// 	{
// 		ft_printf("Invalid PID\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	server_pid = ft_atoi(av[1]);
// 	index = 0;
// 	while (av[2][index])
// 	{
// 		seg_send(server_pid, av[2][index]);
// 		index++;
// 	}
// 	seg_send(server_pid, '\n');
// 	return (0);
// }


#include "../libft/inc/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static volatile sig_atomic_t g_received = 0;

void    confirm_handler(int sig)
{
    if (sig == SIGUSR1)
        g_received = 1;
}

void    seg_send(int pid, unsigned char c)
{
    int    index;

    index = 8;
    while (index-- > 0)
    {
        g_received = 0;
        if ((c >> index) & 1)
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        
        // Wait for confirmation
        while (!g_received)
            usleep(100);
    }
}

int    main(int ac, char **av)
{
    struct sigaction    sa;
    int                server_pid;
    int                index;

    if (ac != 3)
    {
        ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
        exit(EXIT_FAILURE);
    }

    // Set up signal handler for confirmation
    sa.sa_handler = confirm_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("Error setting up signal handler\n");
        exit(EXIT_FAILURE);
    }

    server_pid = ft_atoi(av[1]);
    if (server_pid <= 0)
    {
        ft_printf("Invalid PID\n");
        exit(EXIT_FAILURE);
    }

    index = 0;
    while (av[2][index])
    {
        seg_send(server_pid, av[2][index]);
        index++;
    }
    seg_send(server_pid, '\0');
    return (0);
}