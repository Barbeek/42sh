/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:34:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/04 19:19:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		term_error(char *message)
{
	return (put_error(ERROR, message));
}

int		tent_error(char *ent)
{
	return (put_error2(ERROR, ent, "no entry for terminal"));
}
