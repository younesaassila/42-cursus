/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:56:10 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/15 15:04:27 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;
	t_list	*new_elem;
	void	*new_elem_content;

	elem = lst;
	new_lst = 0;
	while (elem)
	{
		new_elem_content = (*f)(elem->content);
		new_elem = ft_lstnew(new_elem_content);
		if (!new_elem)
		{
			(*del)(new_elem_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		elem = elem->next;
	}
	return (new_lst);
}
