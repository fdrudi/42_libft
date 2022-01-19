/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:40:28 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/18 18:40:32 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(const char *s, char c)
{
	int	i;
	int	start;
	int	wc;

	wc = 0;
	i = 0;
	start = 0;
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if ((i - start - 1) > 0)
				wc++;
			start = i;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (wc);
}

static int	nb_split(int *cnt, const char *s, char *c, char **dest)
{
	while (1)
	{
		if (s[cnt[0]] == *c || s[cnt[0]] == '\0')
		{
			if ((cnt[0] - cnt[1]) > 0)
			{
				dest[cnt[2]] = ft_substr(s, cnt[1], cnt[0] - cnt[1]);
				if (dest[cnt[2]] == NULL)
					return (0);
				cnt[2]++;
			}
			cnt[1] = cnt[0] + 1;
		}
		if (s[cnt[0]] == '\0')
			break ;
		cnt[0]++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		counters[3];
	char	**dest;

	if (s == NULL)
		return (NULL);
	dest = (char **) malloc((nb_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	counters[0] = 0;
	counters[1] = 0;
	counters[2] = 0;
	if (!nb_split (counters, s, &c, dest))
		return (NULL);
	dest[counters[2]] = NULL;
	return (dest);
}
