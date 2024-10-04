/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:08:23 by lfaure            #+#    #+#             */
/*   Updated: 2024/10/04 16:39:42 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_trimc(char const *s1, int *ht)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s1[i])
	{
		if (ht[(unsigned char)s1[i]] != 1)
			c++;
		i++;
	}
	return (c);
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
	while (i < 127)
		ht[i++] = 0;
	i = 0;
	while (set[i])
		ht[(unsigned char)set[i++]] = 1;
	trimc = ft_trimc(s1, ht);
	nstr = malloc(trimc * sizeof(char) + 1);
	i = 0;
	while (s1[i])
	{
		if (ht[(unsigned char)s1[i]] == 0)
			nstr[j++] = s1[i++];
		else
			i++;
	}
	nstr[j] = '\0';
	return (nstr);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strtrim("trim all i and a", "ia"));
	return (0);
}
*/
