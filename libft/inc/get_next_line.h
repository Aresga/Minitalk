/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:44:03 by agaga             #+#    #+#             */
/*   Updated: 2025/01/09 15:59:26 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
//char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
//char	*ft_substr(char *s, unsigned int start, size_t len);
// size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
