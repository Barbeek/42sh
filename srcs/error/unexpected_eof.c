/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_eof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:17:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:32:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		unexpected_eof_error(int type)
{
	char *c;

	if (type == INC_SQT)
		c = "'";
	else if (type == INC_DQT)
		c = "\"";
	else if (type == INC_BTK)
		c = "`";
	else
		c = NULL;
	if (c)
		ft_putendl3_fd(""SH_NAME": "TXT_UNEX_WHILE" `", c, "'", FD_ERR);
	ft_putendl_fd(""SH_NAME": "TXT_SYN_ERR": "TXT_UNEX_EOF"", FD_ERR);
	return (SYNTAX_ERROR);
}
