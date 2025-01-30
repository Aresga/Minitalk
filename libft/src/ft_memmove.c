/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:54:55 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 17:08:10 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		ft_memcpy(d, s, n);
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
