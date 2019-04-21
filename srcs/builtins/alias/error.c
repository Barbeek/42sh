/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:23:08 by pespalie          #+#    #+#             */
/*   Updated: 2019/03/26 20:24:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	alias_invalid_name_error(char *name)
{
	ft_putendl3_fd(""SH_NAME": alias: `", name,
											"': invalid alias name", FD_ERR);
	return (ERROR);
}

int	alias_not_found(char *name)
{
	return (put_error3(ERROR, "alias", name, "not found"));
}

int	alias_wrong_arg_error(char arg)
{
	ft_putstr_fd(""SH_NAME": alias: -", FD_ERR);
	ft_putchar_fd(arg, FD_ERR);
	ft_putendl_fd(": invalid option", FD_ERR);
	ft_putendl_fd("alias: usage: alias [-"ALIAS_OPTIONS"] [name[=value] ... ]",
		FD_ERR);
	return (MAJOR_ERROR);
}
