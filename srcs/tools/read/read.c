/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:51:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 16:20:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		read_all_fd(char **text, int fd)
{
	char		buff[1025];
	int			len;
	int			tot;
	char		*ret;

	tot = 0;
	ret = NULL;
	ft_bzero((char *)buff, 1025);
	while ((len = read(fd, buff, 1024)) == 1024)
	{
		buff[len] = 0;
		try_m(ret = ft_strjoinfs(ret, buff, FT_ARG1));
		ft_bzero((char *)buff, 1025);
		tot += len;
	}
	buff[len] = 0;
	try_m(ret = ft_strjoinfs(ret, buff, FT_ARG1));
	tot += len;
	*text = ret;
	return (tot);
}

char	*read_input(int fd)
{
	char		*ret;
	int			len;

	ret = NULL;
	len = read_all_fd(&ret, fd);
	if (ret)
	{
		while (len > 0 && ret[len - 1] == '\n')
			ret[--len] = 0;
	}
	return (ret);
}

char	*read_heredoc(int fd)
{
	int			len;
	char		*ret;

	ret = NULL;
	len = read_all_fd(&ret, fd);
	return (ret);
}
