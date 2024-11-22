/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:47:55 by aviscogl          #+#    #+#             */
/*   Updated: 2024/11/22 14:53:16 by pnaessen         ###   ########lyon.fr   */
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	str[BUFFER_SIZE + 1];
	int			index;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	index = 1;
	while (1)
	{
		if (str[0] == '\0')
		{
			index = read(fd, str, BUFFER_SIZE);
			if (index <= 0)
				return (line);
			str[index] = '\0';
		}
		newline = ft_strchr(str, '\n');
		if (newline)
		{
			*newline = '\0';
			line = ft_strjoin(line, str);
			ft_strcpy(str, newline + 1);
			line = ft_strjoin(line, "\n");
			return (line);
		}
		line = ft_strjoin(line, str);
		str[0] = '\0';
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("fichier.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
