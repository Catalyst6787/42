/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:08:23 by lfaure            #+#    #+#             */
/*   Updated: 2024/10/07 11:42:57 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_ctrim(char const *s1, int *ht)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	c = 0;
	j = 0;
	while (ht[(unsigned char)s1[i]] == 1)
		i++;
	while (s1[i + c + j])
	{
		if (ht[(unsigned char)s1[i + c + j]] != 1)
		{
			c += j;
			c++;
			j = 0;
		}
		else
			j++;
	}
	return (c);
}

static char	*ft_trim(char const *s1, int *ht, size_t c, char *nstr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ht[(unsigned char)s1[i]] == 1)
		i++;
	while (j < c)
		nstr[j++] = s1[i++];
	nstr[j] = '\0';
	return (nstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ht[127];
	size_t	i;
	size_t	j;
	size_t	trimc;
	char	*nstr;

	i = 0;
	j = 0;
	if (set[0])
	{
		while (i < 127)
			ht[i++] = 0;
		i = 0;
		while (set[i])
			ht[(unsigned char)set[i++]] = 1;
		trimc = ft_ctrim(s1, ht);
	}
	else
		trimc = ft_strlen(s1);
	nstr = malloc((trimc + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	nstr = ft_trim(s1, ht, trimc, nstr);
	return (nstr);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strtrim("AuAuA", "A"));
	return (0);
}
*/
