/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:16:10 by agaga             #+#    #+#             */
/*   Updated: 2025/01/09 14:31:01 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_putstr(const char *str)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}
