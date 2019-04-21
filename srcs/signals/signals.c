/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:43:23 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:14:06 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 1      [1]    32000 hangup     bash --posix
** 2     rien
** 3     rien
** 4    [1]    32336 illegal hardware instruction  bash --posix
** 5    [1]    32364 trace trap  bash --posix
** 6    [1]    32506 abort      bash --posix
** 7    [1]    32625 EMT instruction  bash --posix
** 8    [1]    32706 floating point exception  bash --posix
** 9    [1]    32782 killed     bash --posix      (SGKILL IMPOS A RECUP)
** 10   [1]    32811 bus error  bash --posix
** 11	[1]    32852 segmentation fault  bash --posix
** 12	[1]    32909 invalid system call  bash --posix
** 13		-Rien- quitte juste
** 14 	  [2]    33836 alarm      bash --posix
** 15   fait rien
** 16   fait rien
** 17 [1]  + 33605 suspended (signal)  bash --posix(SIGSTOP IMPOSS A RECUP)
** 18   fait rien
** 19 [1]  + 33992 continued  bash --posix
** 20   fait rien
** 21   fait rien
** 22   fait rien
** 23   fait rien
** 24 [1]    33576 cpu limit exceeded  bash --posix
** 25 [1]    33519 file size limit exceeded  bash --posix
** 26 [1]    33496 virtual time alarm  bash --posix
** 27 [1]    33432 profile signal  bash --posix
** 28   fait rien
** 29   fait rien
** 30 [1]    33362 user-defined signal 1  bash --posix
** 31 [1]    33297 user-defined signal 2  bash --posix
*/

void	signal_handler(int sig)
{
	t_data	*data;

	data = get_data();
	if (sig == SIGINT)
		handle_sigint();
	else if (sig == SIGWINCH)
		handle_sigwinch(data);
}

void	catch_signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, SIG_IGN);
}
