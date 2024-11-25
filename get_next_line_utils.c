/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:57 by pnaessen          #+#    #+#             */
/*   Updated: 2024/11/25 11:27:32 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*str;
	size_t	i;
	size_t	size;

	size = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s2[size] != '\0' && s2[size] != '\n')
		size++;
	if (s2[size] == '\n')
		size++;
	i = 0;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_update(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i + j] != '\0')
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}
