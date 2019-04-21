/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:42:17 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/20 11:31:39 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/

# include <stdio.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libs
*/

# include "libft.h"
# include <term.h>

/*
** Defines
*/

# include "defines.h"

/*
** Typedef / Structs
*/

# include "structs.h"

/*
** Headers 42sh
*/

# include "prototypes.h"

#endif
