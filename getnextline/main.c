#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_strjoin.c"

char	*ft_strjloin(char const *s1, char const *s2);


char *get_next_line(int fd)
{
	int		bufsize = 7;
	char	*line;
	char	buf[bufsize + 1];
	int		chars_read;
	int		i;
	int		done = 0;

	i = 0;
	line = malloc(1);
	line[0] = '\0';
	while((chars_read = read(fd, buf, bufsize)) && !done)
	{
		buf[chars_read] = '\0';
		while(i < bufsize && buf[i] && buf[i] != '\n')
			i++;
		if (i < bufsize)
		{
			return (ft_strljoin(line, buf, i));
			done = 1;
		}
		i = 0;
		line = ft_strljoin(line, buf, bufsize);
	}
	return(ft_strljoin(line, buf, chars_read + 10));
}

int	main(void)
{
	int	fd;
	fd = open("file.txt", O_RDONLY);
	printf("fd of file %d\n", fd);
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf("%s\n", get_next_line(fd));

}