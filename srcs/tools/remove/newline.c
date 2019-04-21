/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:04:58 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 16:40:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*remove_esc_newlines(char *line)
{
	char *ptr;

	if (line)
	{
		ptr = line;
		while (*ptr)
		{
			if (*ptr == '\\' && *(ptr + 1) == '\n')
				ft_strmove(ptr, ptr + 2);
			else
			{
				if (*ptr == '"')
					ptr = walkdoublequote(ptr + 1);
				else if (*ptr == '\'')
					ptr = walksimplequote(ptr + 1);
				else if (*ptr == '`')
					ptr = walkbacktick(ptr + 1);
				if (*ptr)
					++ptr;
			}
		}
	}
	return (line);
}

char	*remove_last_newline(char *line)
{
	char *ptr;

	if (line && (ptr = ft_strrchr(line, '\n')))
		*ptr = 0;
	return (line);
}

char	*remove_heredoc_esc_newlines(char *line)
{
	char *ptr;

	if (line)
	{
		ptr = line;
		while (*ptr)
		{
			if (*ptr == '\\' && *(ptr + 1) == '\n')
				ft_strmove(ptr, ptr + 2);
			++ptr;
		}
	}
	return (line);
}
