/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:53:54 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 17:06:40 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*ptr == uc)
		{
			return ((void *)ptr);
		}
		ptr++;
	}
	return (NULL);
}
