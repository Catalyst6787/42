/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:40:10 by lfaure            #+#    #+#             */
/*   Updated: 2024/10/04 15:29:18 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!s || len == 0 || start > ft_strlen(s))
	{
		nstr = ft_calloc(1, sizeof(char));
		nstr[0] = '\0';
		return (nstr);
	}
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
/*
#include <stdio.h>
int	main(void)
{
	char *s = "aaa";
	printf("%s\n", ft_substr(s, 1, 0));
	return (0);
}
*/
