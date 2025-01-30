/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:52:05 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 17:08:55 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;
	size_t		str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
