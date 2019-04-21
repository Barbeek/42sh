/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:51:34 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/15 16:20:12 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		delpipelist(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

void		deloplst(void *content, size_t size)
{
	(void)size;
	lstdel(&(*((t_pipeline **)(content)))->pipeline, delpipelist);
	ft_memdel((void **)((t_pipeline **)(content)));
	ft_memdel((void **)&content);
}

void		lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			temp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = temp;
		}
	}
}

void		lstaddend(t_list **alst, t_list *new)
{
	t_list		*temp;
	t_list		*list;

	if (new != NULL)
	{
		temp = *alst;
		list = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		*alst = list;
	}
}
