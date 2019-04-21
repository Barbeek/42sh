/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:52:17 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/11 12:45:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

/*
** Stringbuffer string
*/

typedef struct	s_strbuffer
{
	char	*str;
	size_t	length;
	size_t	max_len;
}				t_strbuffer;

/*
** List
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_alist
{
	char			*key;
	void			*content;
	size_t			content_size;
	struct s_alist	*next;
}				t_alist;

/*
** ArrayList collection
*/

typedef struct	s_arlist
{
	size_t		length;
	t_list		*list;
}				t_arlist;

#endif
