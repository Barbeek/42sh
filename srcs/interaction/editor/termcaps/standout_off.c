/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standout_off.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:29:51 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/19 17:01:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	tc_standout_off(void)
{
	tputs(tgetstr("se", NULL), 1, sh_putchar);
}
