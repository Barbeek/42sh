/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:07:57 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 22:07:36 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_if(char **tab1, char **tab2, char flag)
{
	if (tab1 && (flag & FT_ARG1))
		free(tab1);
	if (tab2 && (flag & FT_ARG2))
		free(tab2);
	return (NULL);
}

char		**ft_strtabjoinfs(char **tab1, char **tab2, char flag)
{
	char	**res;
	size_t	len1;

	len1 = tab1 ? ft_strtablen(tab1) : 0;
	if ((res = ft_strtaballoc(len1 + (tab2 ? ft_strtablen(tab2) : 0))))
	{
		if (tab1)
			ft_strtabcpy(res, tab1);
		if (tab2)
			ft_strtabcpy(res + len1, tab2);
	}
	free_if(tab1, tab2, flag);
	return (res);
}

char		*ft_strtabstrjoin(char **tab, char delim)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (!tab || !*tab)
		return (NULL);
	i = 0;
	len = ft_strtabstrlen(tab, &i) + i - 1;
	if (!(ret = ft_stralloc(len)))
		return (NULL);
	i = 0;
	while (*tab)
	{
		if (i > 0)
			ret[i++] = delim;
		i += ft_strlcpy(ret + i, *(tab++), len + 1);
	}
	return (ret);
}

char		*ft_strtabstrjoinf(char **tab, char delim)
{
	char	*ret;

	ret = ft_strtabstrjoin(tab, delim);
	ft_strtabdel(&tab);
	return (ret);
}
