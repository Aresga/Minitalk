/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:43:32 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 17:05:50 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_numlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	digits;
	int		num;

	num = n;
	digits = ft_numlen(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	while (digits-- > 0)
	{
		result[digits] = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		*result = '-';
	return (result);
}
