/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:02 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/06 21:10:51 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// c is the choice of action to perform
char*	get_stat(char* s1, int c)
{
	static char	*stat;

	if (c == 0)
	{
		if(stat)
			free(stat);
		stat = NULL;
	}
	else if (c == 1)
	{
		if(stat)
			free(stat);
		stat = s1;
	}
	else if (c == 2)
		return(stat);
	else if (c == 3)
		stat = NULL;
	return(stat);

}

int	checkline(char* line)
{
	int i;

	i = 0;
	if (!line)
		return(-1);
	while(line[i])
	{
		if (line[i] == '\n' && line[i + 1])
			return(2);
		else if (line[i] == '\n')
			return(1);
		i++;
	}
	return(0);
}
char	*until_nl(char *line, int freeline)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (!line)
		return(NULL);
	while(line[i])
	{
		if (line[i] == '\n' && freeline)
		{
			tmp = ft_substr(line, 0, i + 1);
			return(free(line), line = NULL, tmp);
		}
		else if (line[i] == '\n')
			return(ft_substr(line, 0, i + 1));
		i++;
	}
	return(NULL);
}
char	*after_nl(char *line)
{
	unsigned int i;

	i = 0;
	if (!line)
		return(NULL);
	while(line[i])
	{
		if (line[i] == '\n')
			return(ft_substr(line, i + 1, ft_strlen(line)));
		i++;
	}
	return(NULL);
}

char*	get_next_line(int fd)
{
	int		chars_read;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	
	tmp = NULL;
	if (get_stat(NULL, 2) && checkline(get_stat(NULL, 2)) == 2)
	{
		tmp = until_nl(get_stat(NULL, 2), 0);
		get_stat(after_nl(get_stat(NULL, 2)), 1);
		return(tmp);
	}
	if (get_stat(NULL, 2) && checkline(get_stat(NULL, 2)) == 1)
		return(get_stat(NULL, 0), until_nl(get_stat(NULL, 2), 0));
	else if (get_stat(NULL, 2))
		tmp = ft_strjoin(get_stat(NULL, 2), "");
	chars_read = read(fd, buf, BUFFER_SIZE);
	while(chars_read > 0)
	{
		buf[chars_read] = '\0';
		tmp = ft_strjoin(get_stat(NULL, 2), buf);
		if (checkline(tmp) == 2)
			return(get_stat(after_nl(tmp), 1), until_nl(tmp, 1));
		else if (checkline(tmp) == 1)
			return(get_stat(NULL, 0), tmp);
		get_stat(tmp, 1);
		chars_read = read(fd, buf, BUFFER_SIZE);
	}
	return(get_stat(NULL, 3), tmp);
}


int main(void)
{
	int fd;
	/*
	printf("test checkline: \n");
	printf("empty: %d\n", checkline(""));
	printf("NULL: %d\n", checkline(NULL));
	printf("nl with rest: %d\n", checkline("hello\n i am naughty"));
	printf("nl no rest: %d\n", checkline("hello\n"));
	printf("just nl: %d\n", checkline("\n"));
	printf("multiple nl: %d\n", checkline("\n\n\n\n"));
	printf("\n");
	printf("test until nl: \n");
	printf("empty: %s\n", until_nl("", 0));
	printf("NULL: %s\n", until_nl(NULL, 0));
	printf("nl with rest: %s\n", until_nl("hello\n i am naughty", 0));
	printf("nl no rest: %s\n", until_nl("hello\n", 0));
	printf("just nl: %s\n", until_nl("\n", 0));
	printf("multiple nl: %s\n", until_nl("\n\n\n\n", 0));
	printf("\n");
	
	printf("test after nl: \n");
	printf("empty: %s\n", after_nl(""));
	printf("NULL: %s\n", after_nl(NULL));
	printf("nl with rest: %s\n", after_nl("hello\n i am naughty"));
	printf("nl with rest containing nl: %s\n", after_nl("hello\n i am \n naughty \n naughty"));
	printf("nl no rest: %s\n", after_nl("hello\n"));
	printf("just nl: %s\n", after_nl("\n"));
	printf("multiple nl: %s\n", after_nl("\n\n\n\n"));
	
	printf("\n");
	printf("test get stat: \n");
	printf("free: %s\n", get_stat(NULL, 0));
	printf("assigne test: %s\n", get_stat(ft_strdup("test"), 1));
	printf("get value: %s\n", get_stat(NULL, 2));
	printf("free: %s\n", get_stat(NULL, 0));
	printf("get value: %s\n", get_stat(NULL, 2));
	*/

	fd = open("./files/multiple_nl.txt", O_RDONLY);
	
	char* returnvalue;
	/*
	while((returnvalue = get_next_line(fd)) && returnvalue)
	{
		printf("%s", returnvalue);
		free(returnvalue);
		returnvalue = NULL;
	}
	*/

	int i = 0;
	char	*tmp;
	while(i != 10)
	{
		returnvalue = get_next_line(fd);
		printf("%s", returnvalue);
		free(returnvalue);
		returnvalue = NULL;
		if (i == 11)
			{
				tmp = ft_strdup("");
				free(tmp);
				tmp = NULL;
			}
		i++;
	}

	printf("\n");
	/*
		
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	ft_strdup("");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	*/	

}

