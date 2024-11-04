/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:53:16 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/04 16:56:20 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);
	
}

char	*ft_strdup(const char *src) // pas forcement utile
{
	int		len;
	char	*nstr;
	int		i;

	i = 0;
	len = ft_strlen(src);
	nstr = (char *)malloc(sizeof(*src) * (len + 1));
	if (!nstr)
		return (NULL);
	while (src[i])
	{
		nstr[i] = src[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strljoin(char const *s1, char const *s2, size_t len)
{
	size_t	totlen;
	size_t	i;
	size_t	j;
	char	*nstr;

	i = 0;
	j = 0;
	if (ft_strlen(s2) > len)
		totlen = ft_strlen(s1) + len;
	else
		totlen = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(sizeof(char) * (totlen + 1));
	if (!nstr)
		return (NULL);
	while (s1 && s1[i])
		nstr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] && i < len)
		nstr[j++] = s2[i++];
	nstr[j] = '\0';
	return (nstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (nstr = ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	nstr = ft_calloc(len + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	while (s[i] && i < len)
	{
		nstr[i] = s[start + i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	c;

	c = 0;
	tmp_ptr = (unsigned char *) b;
	while (n > 0)
	{
		*(tmp_ptr++) = (unsigned char) c;
		n--;
	}
}
