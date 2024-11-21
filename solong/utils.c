#include "so_long.h"

static size_t	ft_nbrlen(int nbr)
{
	size_t	nbrlen;

	nbrlen = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbrlen++;
		nbr = nbr / 10;
	}
	return (nbrlen);
}

static char	*ft_write_nbr(int n, char *res, size_t nbrlen, int neg)
{
	while (nbrlen > 0)
	{
		res[nbrlen - 1 + neg] = (n % 10 + 48);
		n = n / 10;
		nbrlen--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_itoa(int n)
{
	int		neg;
	size_t	nbrlen;
	char	*res;

	neg = 0;
	if (n == -2147483648)
	{
		res = malloc(12 * sizeof(char));
		if (!res)
			return (NULL);
		ft_strlcpy (res, "-2147483648", 12);
		return (res);
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	nbrlen = ft_nbrlen(n);
	res = malloc((nbrlen + 1 + neg) * sizeof(char));
	if (!res)
		return (NULL);
	res[nbrlen + neg] = '\0';
	return (ft_write_nbr(n, res, nbrlen, neg));
}
