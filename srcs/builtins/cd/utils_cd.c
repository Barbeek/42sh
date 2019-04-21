/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:43:02 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/11 14:43:31 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_strtab_del(char ***arr)
{
	int		i;

	if (!(*arr))
		return ;
	if (!(*arr)[0])
	{
		ft_memdel((void **)arr);
		*arr = NULL;
		return ;
	}
	i = -1;
	while ((*arr)[++i])
		ft_strdel(&(*arr)[i]);
	ft_strdel(&(*arr)[i]);
	ft_memdel((void **)arr);
	*arr = NULL;
}

int		ft_stringtab_len(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

char	*ft_strjointab(char **arr, char sep)
{
	int		i;
	int		len;
	char	*result;
	char	sepp[2];

	i = -1;
	len = 0;
	sepp[0] = sep;
	sepp[1] = '\0';
	if (arr == NULL || !arr[0])
		return (ft_strdup(sepp));
	while (arr[++i])
		len += ft_strlen(arr[i]);
	len += i;
	if (!(result = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		ft_strcat(result, sepp);
		ft_strcat(result, arr[i]);
	}
	return (result);
}
