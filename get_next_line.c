/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:47:55 by aviscogl          #+#    #+#             */
/*   Updated: 2024/11/21 19:47:55 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_newline(const char *str) {
    while (*str) {
        if (*str == '\n')
            return (char *)str;
        str++;
    }
    return NULL;
}

char *get_next_line(int fd) {
    char buffer[BUFFER_SIZE + 1];
    int index_read;

    index_read = read(fd, buffer, BUFFER_SIZE);
    if (index_read <= 0)
        return NULL; 
    buffer[index_read] = '\0';

    return find_newline(buffer);
}

int main() {
    int fd = open("fichier.txt", );
    char *line;

    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
