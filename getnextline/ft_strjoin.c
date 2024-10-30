/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:45:40 by lfaure            #+#    #+#             */
/*   Updated: 2024/10/29 14:10:41 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	while (s1[i])
		nstr[j++] = s1[i++];
	i = 0;
	while (s2[i] && i < len)
		nstr[j++] = s2[i++];
	nstr[j] = '\0';
	return (nstr);
}
/*
#include <stdio.h>
int	main(void)
{
    char *result = ft_strljoin("Welcome to ", "42 The School where nerds are born", 6);
    if (result) {
        printf("%s\n", result);
        free(result);  // Free the allocated memory after use
    }
    return (0);
}
*/