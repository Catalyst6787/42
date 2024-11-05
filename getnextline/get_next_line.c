/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:02 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/05 16:38:48 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_line(char *line, int no_alloc)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
		{
			if (!no_alloc)
				return (ft_substr(line, 0, i));
			else
				return ("string");
		}
	}
	return (NULL);
}

static char	*trim_stat(char *line)
{
	unsigned int	i;
	char			*nline;

	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
		{
			nline = ft_substr(line, i, ft_strlen(line));
			free(line);
			line = NULL;
			return (nline);
		}
	}
	return (NULL);
}

static char	*trim_line(char *line)
{
	unsigned int	i;
	char			*nline;

	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
		{
			nline = ft_substr(line, i, ft_strlen(line));
			return (nline);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stat;
	int			chars_read;
	char		*line;
	char		*tmp;

	chars_read = 1;
	line = NULL;
	tmp = NULL;
	if (fd < 0)
		return (NULL);
	if (stat && check_line(stat, 1))
	{
		tmp = check_line(stat, 0);
		stat = trim_stat(stat);
		if (!stat)
			return (NULL);
		return (tmp);
	}
	else if (stat && stat[0])
		line = ft_strdup(stat); // si je veux grater une fonction
	chars_read = read(fd, buf, BUFFER_SIZE);
	while (chars_read > 0)
	{
		buf[chars_read] = '\0';
		line = ft_strljoin(line, buf, BUFFER_SIZE +1);
		if (!line)
			return (NULL);
		if (check_line(line, 1))
		{
			free(stat);
			stat = trim_line(line);
			if (!stat)
				return (NULL);
			tmp = line;
			return (line = check_line(line, 0), free(tmp), tmp = NULL, line);
		}
		chars_read = read(fd, buf, BUFFER_SIZE);
	}
	if (chars_read == -1)
		return (free(stat), stat = NULL, free(line), line = NULL, NULL);
	return (free(stat), stat = NULL, line);
}
/*
int main(void)
{
	int fd;

	fd = open("./files/variable_nls.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
