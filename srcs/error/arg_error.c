/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:43:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:33:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		wrong_arg_error(char arg)
{
	ft_putstr_fd(""SH_NAME": invalid option -- ", FD_ERR);
	ft_putchar_fd(arg, FD_ERR);
	ft_putstr_fd("\nUsage:  ./"SH_NAME" [-"SH_OPTIONS"] ...\n", FD_ERR);
	return (MAJOR_ERROR);
}
