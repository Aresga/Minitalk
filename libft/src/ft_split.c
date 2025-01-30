/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:04:13 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 19:34:36 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			i++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (i);
}

static int	free_mem(char **str, int i)
{
	while (i-- > 0)
		free(str[i]);
	free(str);
	return (-1);
}

static int	ft_split_put(char **result, char const *s, char c)
{
	size_t	word_len;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c))
				word_len = ft_strchr(s, c) - s;
			else
				word_len = ft_strlen(s);
			result[i] = ft_substr(s, 0, word_len);
			if (!result[i++])
			{
				free_mem(result, i);
			}
			s += word_len;
		}
	}
	result[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (ft_split_put(result, s, c) == -1)
		return (NULL);
	return (result);
}
