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

char	*ft_strjoin(char *s1, char *s2)
{
    size_t	len1;
    size_t	len2;

	len1 = ft_strlen(s1);
	len2 = 0;
    while (s2[len2] && s2[len2] != '\n')
        len2++;
    if (s2[len2] == '\n')
        len2++;
    char	*str = malloc(len1 + len2 + 1);
    if (!str)
        return (NULL);
    ft_memcpy(str, s1, len1);
    ft_memcpy(str + len1, s2, len2);
    str[len1 + len2] = '\0';
    free(s1);
    return (str);
}

void	ft_update(char *str)
{
    int	i;
    int	j;

	j = 0;
	i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    while (str[i])
        str[j++] = str[i++];
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
