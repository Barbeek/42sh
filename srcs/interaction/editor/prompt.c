/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:26:20 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/20 11:12:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const char	*g_prompts[] = {TTY_DFLT, TTY_DFLT, TTY_BKS, TTY_SQT,
	TTY_DQT, TTY_BTK, TTY_PAR, TTY_BRA, TTY_AND, TTY_OR, TTY_PIP, TTY_HER,
	TTY_HER_BKS, 0};

static const size_t	g_prompts_len[] = {TTY_DFLT_L, TTY_DFLT_L, TTY_BKS_L,
	TTY_SQT_L, TTY_DQT_L, TTY_BTK_L, TTY_PAR_L, TTY_BRA_L, TTY_AND_L, TTY_OR_L,
	TTY_PIP_L, TTY_HER_L, TTY_HER_BKS_L, 0};

void	display_prompt(t_edl *edl)
{
	if (edl->prompt.val)
	{
		tc_clear_effects();
		ft_putstr_fd(edl->prompt.val, FD_PRO);
		get_prompt_position(edl);
	}
}

void	set_prompt(t_edl *edl)
{
	if (edl->incomp_type >= 0 && edl->incomp_type <= 12)
	{
		edl->prompt.val = (char *)g_prompts[edl->incomp_type];
		edl->prompt.len = (size_t)g_prompts_len[edl->incomp_type];
	}
}
