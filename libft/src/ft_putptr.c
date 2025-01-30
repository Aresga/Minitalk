/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:18:56 by agaga             #+#    #+#             */
/*   Updated: 2025/01/09 14:30:58 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				i;
	unsigned long	nbr;

	i = 0;
	nbr = (unsigned long)ptr;
	if (nbr == 0)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += ft_putnbr_base(nbr, 16, 6);
	}
	return (i);
}
