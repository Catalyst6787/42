/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:02 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/04 17:03:05 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_line(char *line, int no_alloc)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (line[i++] == '\n' && !no_alloc)
		{
			if (!no_alloc)
				return(ft_substr(line, 0, i));
			else
				return("string");
		}
	}
	return(NULL);
}

char *trim_stat(char *line)
{
	unsigned int i;
	char *nline;

	i = 0;
	while(line[i])
	{
		if (line[i++] == '\n')
		{
			nline = ft_substr(line, i, ft_strlen(line));
			free(line); // to free the previous line
			line = NULL;
			return(nline);
		}
	}
	return(NULL); 
}

char *trim_line(char *line)
{
	unsigned int i;
	char *nline;

	i = 0;
	while(line[i])
	{
		if (line[i++] == '\n')
		{
			nline = ft_substr(line, i, ft_strlen(line));
			return(nline);
		}
	}
	return(NULL); 
}

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	static char *stat;
	int	chars_read;
	char *line;
	char *tmp;
	
	line = NULL;
	if (fd < 0)
		return(NULL);
	if (!stat)
	{
		stat = malloc(1);
		if (!stat)
			return(NULL);
		stat[0] = '\0';
	}
	if (check_line(stat, 1))
	{
		tmp = check_line(stat, 0);
		stat = trim_stat(stat);
		if (!stat)
			return(NULL);
		return(tmp);
	}
	else
		line = stat;
	while((chars_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (chars_read < 0)
			return(NULL);
		buf[chars_read] = '\0';
		line = ft_strljoin(line, buf, BUFFER_SIZE +1);
		if (!line)
			return (NULL);
		if (check_line(line, 0))
		{
			tmp = line;
			stat = trim_line(line);
			if (!stat)
				return(NULL);
			line = check_line(line, 0);
			free(tmp);
			tmp = NULL;
			return(line);
		}
	}
	return(NULL);
}
/*
int main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
