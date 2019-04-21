/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmvchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:11:57 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/27 16:48:02 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strrmvchr(char *s)
{
	if (s && *s)
	{
		s++;
		while (*s)
		{
			*(s - 1) = *s;
			s++;
		}
		*(s - 1) = 0;
	}
}

char	*ft_strrmvallchr(char *s, char c)
{
	char *beg;
	char *end;

	if (s && *s)
	{
		beg = s;
		end = s;
		while (*end)
		{
			if (*end == c)
				++end;
			*(beg++) = *(end++);
		}
		*beg = *end;
	}
	return (s);
}
