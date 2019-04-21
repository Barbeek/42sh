/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:02:10 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/03 14:53:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstrlpad(size_t width, char c, char const *s)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, &c, width - len);
		write(1, s, len);
	}
}

void	ft_putstrrpad(size_t width, char c, char const *s)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		write(1, &c, width - len);
	}
}

void	ft_putstrlpad_fd(char const *s, char c, size_t size, int fd)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		while (size-- > len)
			write(fd, &c, 1);
		write(fd, s, len);
	}
}

void	ft_putstrrpad_fd(char const *s, char c, size_t size, int fd)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		while (size-- > len)
			write(fd, &c, 1);
	}
}
