/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:47:55 by aviscogl          #+#    #+#             */
/*   Updated: 2024/11/25 14:50:32 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
        {
                if (s[i] == (unsigned char)c)
                        return ((char *)(s + i));
                i++;
        }
        if ((unsigned char)c == '\0')
                return ((char *)(s + i));
        return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	str[BUFFER_SIZE + 1];
	int			index;

	index = 1;
	line = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (NULL);
	while (index > 0 && !ft_strchr(line, '\n'))
	{
		index = read(fd, str, BUFFER_SIZE);
		if (index == -1)
			return (ft_bzero(str), free(line), NULL);
		str[index] = '\0';
		line = ft_strjoin(line, str);
		if (!line)
			return (NULL);
	}
	if (index == 0 && str[0] != '\0')
		line = ft_strjoin(line, str);
	ft_update(str);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}


int	main(void)
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
}
