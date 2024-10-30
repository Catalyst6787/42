/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:02 by lfaure            #+#    #+#             */
/*   Updated: 2024/10/30 20:03:25 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	unsigned int	i;
	static char 	*stat;
	char			*line;
	char			*tmp;
	char			buf[BUFFER_SIZE + 1];
	int				chars_read;

	chars_read = 0;
	i = 0;
	if (!stat)
	{
		stat = malloc(1);
		stat[0] = '\0';
	}
	else if (check_stat()
		return(check_stat
	line = malloc(1);
	line[0] = '\0';
	while((chars_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[chars_read] = '\0';
		tmp = ft_strljoin(stat, buf, BUFFER_SIZE + 1);
		while(tmp[i])
		{
			if (tmp[i] == '\n')
			{
				line = ft_strljoin(line, tmp, i + 1);
				stat = ft_substr(tmp, i + 1, ft_strlen(tmp) - i + 1);
				return(line);
			}
			i++;
		}
		i = 0;
		line = ft_strljoin(line, tmp, BUFFER_SIZE + 1);
	}
	return(line);
}

char *check_stat(static char stat)
{
	i = 0;
	while(stat[i])
	{
		if (stat[i] == '\n')
		{
			line = ft_strljoin(line, stat, i + 1);
			stat = ft_substr(tmp, i + 1, ft_strlen(tmp) - i + 1);
			return(line);
		}
		i++;
	}
	return(NULL)
}


#include <stdio.h>
int main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//printf("\n");
	printf("%s", get_next_line(fd));
	//printf("\n");
	printf("%s", get_next_line(fd));
	//printf("\n");
	printf("%s", get_next_line(fd));
	//printf("\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
