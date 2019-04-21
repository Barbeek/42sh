/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:29:59 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 12:41:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	hash_wrong_arg_error(char arg)
{
	ft_putstr_fd(""SH_NAME": hash: -", FD_ERR);
	ft_putchar_fd(arg, FD_ERR);
	ft_putendl_fd(": invalid option", FD_ERR);
	ft_putendl_fd("hash: usage: hash [-"HASH_OPTIONS"] [name]",
		FD_ERR);
	return (MAJOR_ERROR);
}

int	hash_not_found(char *name)
{
	return (put_error3(ERROR, "hash", name, "not found"));
}
