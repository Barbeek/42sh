/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:03:04 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/18 14:10:32 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	check_user(struct stat *buf, char *perm)
{
	perm[1] = (buf->st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (buf->st_mode & S_IWUSR) ? 'w' : '-';
	if (buf->st_mode & S_ISUID)
		perm[3] = (buf->st_mode & S_IXUSR) ? 's' : 'S';
	else
		perm[3] = (buf->st_mode & S_IXUSR) ? 'x' : '-';
}

void	check_group(struct stat *buf, char *perm)
{
	perm[4] = (buf->st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (buf->st_mode & S_IWGRP) ? 'w' : '-';
	if (buf->st_mode & S_ISGID)
		perm[6] = (buf->st_mode & S_IXGRP) ? 's' : 'S';
	else
		perm[6] = (buf->st_mode & S_IXGRP) ? 'x' : '-';
}

void	check_other(struct stat *buf, char *perm)
{
	perm[7] = (buf->st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (buf->st_mode & S_IWOTH) ? 'w' : '-';
	if (buf->st_mode & S_ISVTX)
		perm[9] = (buf->st_mode & S_IXOTH) ? 't' : 'T';
	else
		perm[9] = (buf->st_mode & S_IXOTH) ? 'x' : '-';
}

char	*get_type_file(struct stat *buf, char *perm)
{
	if ((buf->st_mode & S_IFMT) == S_IFREG)
		perm[0] = '-';
	if ((buf->st_mode & S_IFMT) == S_IFLNK)
		perm[0] = 'l';
	if ((buf->st_mode & S_IFMT) == S_IFSOCK)
		perm[0] = 's';
	if ((buf->st_mode & S_IFMT) == S_IFDIR)
		perm[0] = 'd';
	if ((buf->st_mode & S_IFMT) == S_IFBLK)
		perm[0] = 'b';
	if ((buf->st_mode & S_IFMT) == S_IFCHR)
		perm[0] = 'c';
	if ((buf->st_mode & S_IFMT) == S_IFIFO)
		perm[0] = 'p';
	return (perm);
}

char	*get_permissions(char *pathname)
{
	char		*perm;
	struct stat *buf;

	try_m(perm = (char *)ft_memalloc(sizeof(char *) * 10));
	try_m(buf = malloc(sizeof(struct stat)));
	if (lstat(pathname, buf) < 0)
	{
		free(buf);
		return (NULL);
	}
	perm = get_type_file(buf, perm);
	check_user(buf, perm);
	check_group(buf, perm);
	check_other(buf, perm);
	free(buf);
	return (perm);
}
