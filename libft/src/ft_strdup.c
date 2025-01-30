/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:42:57 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 17:07:19 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(src) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
