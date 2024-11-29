/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:05:34 by pnaessen          #+#    #+#             */
/*   Updated: 2024/11/29 09:54:03 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

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
	static char	str[OPEN_MAX][BUFFER_SIZE + 1] = {0};
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	index = 1;
	line = ft_strdup(str[fd]);
	if (!line)
		return (NULL);
	while (index > 0 && !ft_strchr(line, '\n'))
	{
		index = read(fd, str[fd], BUFFER_SIZE);
		if (index == -1)
			return (ft_bzero(str[fd], BUFFER_SIZE), free(line), NULL);
		str[fd][index] = '\0';
		line = ft_strjoin(line, str[fd]);
		if (!line)
			return (NULL);
	}
	if (index == 0 && !line[0])
		return (free(line), NULL);
	ft_update(str[fd]);
	return (line);
}

/*int main(void)
{
    int fd;
    char *line;

    // Ouvrir un fichier en lecture (assure-toi que le fichier existe)
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Lire et afficher chaque ligne du fichier
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // Affiche la ligne lue
        free(line);  // Libère la mémoire allouée pour la ligne
    }

    // Ferme le fichier
    close(fd);
    return 0;
}*/
