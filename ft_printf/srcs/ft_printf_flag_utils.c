/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:51:18 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 10:51:31 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*ft_add_flag(t_list **flags, char character,
		int (*handler)(va_list))
{
	t_flag	*flag;
	t_list	*item;

	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->character = character;
	flag->handler = handler;
	item = ft_lstnew(flag);
	if (!item)
	{
		free(flag);
		return (NULL);
	}
	ft_lstadd_back(flags, item);
	return (item);
}

t_list	*ft_get_flags(void)
{
	t_list	*flags;

	flags = NULL;
	if (!ft_add_flag(&flags, 'c', &ft_handler_char)
		|| !ft_add_flag(&flags, 's', &ft_handler_str)
		|| !ft_add_flag(&flags, 'p', &ft_handler_ptr)
		|| !ft_add_flag(&flags, 'd', &ft_handler_int)
		|| !ft_add_flag(&flags, 'i', &ft_handler_int)
		|| !ft_add_flag(&flags, 'u', &ft_handler_uint)
		|| !ft_add_flag(&flags, 'x', &ft_handler_uint_hex_lower)
		|| !ft_add_flag(&flags, 'X', &ft_handler_uint_hex_upper))
	{
		ft_lstclear(&flags, &free);
		return (NULL);
	}
	return (flags);
}

t_flag	*ft_get_flag(t_list *flags, char character)
{
	t_list	*item;
	t_flag	*flag;

	item = flags;
	while (item)
	{
		flag = item->content;
		if (flag->character == character)
			return (flag);
		item = item->next;
	}
	return (NULL);
}
