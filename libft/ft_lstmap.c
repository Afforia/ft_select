/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:44:43 by thaley            #+#    #+#             */
/*   Updated: 2019/01/17 17:44:45 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstfree(t_list **head)
{
	while ((*head)->next)
		ft_lstfree(&((*head)->next));
	free((*head)->content);
	(*head)->content = NULL;
	free(*head);
	(*head) = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	head = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
			ft_lstfree(&head);
		new = new->next;
	}
	return (head);
}
