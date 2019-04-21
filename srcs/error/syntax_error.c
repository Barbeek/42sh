/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:32:52 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:32:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		syntax_error(char *word, int subcmd)
{
	if (word)
	{
		ft_putstr_fd(""SH_NAME"", FD_ERR);
		if (subcmd)
			ft_putstr_fd(": command substitution", FD_ERR);
		ft_putstr_fd(": syntax error near unexpected token `", FD_ERR);
		if (*word == '\n')
			ft_putstr_fd("newline", FD_ERR);
		else
			ft_putstr_fd(word, FD_ERR);
		ft_putstr_fd("'\n", FD_ERR);
	}
	return (SYNTAX_ERROR);
}
