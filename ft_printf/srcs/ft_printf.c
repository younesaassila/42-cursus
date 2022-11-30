/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:41:38 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 11:26:48 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_free(t_list **flags, va_list arg_ptr)
{
	ft_lstclear(flags, &free);
	va_end(arg_ptr);
}

static int	ft_printf_aux(t_list *flags, va_list arg_ptr, const char *str,
		size_t *i)
{
	int		printed;
	t_flag	*flag;

	printed = 0;
	flag = ft_get_flag(flags, str[*i + 1]);
	if (str[*i] == '%' && str[*i + 1] != '\0' && flag)
	{
		printed = (flag->handler)(arg_ptr);
		(*i)++;
	}
	else
	{
		printed = write(STDOUT_FILENO, &str[*i], 1);
		if (str[*i] == '%' && str[*i + 1] == '%')
			(*i)++;
	}
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	t_list	*flags;
	va_list	arg_ptr;
	int		total_printed;
	int		printed;
	size_t	i;

	flags = ft_get_flags();
	if (!str || !flags)
		return (-1);
	va_start(arg_ptr, str);
	total_printed = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		printed = ft_printf_aux(flags, arg_ptr, str, &i);
		if (printed == -1)
		{
			ft_printf_free(&flags, arg_ptr);
			return (-1);
		}
		total_printed += printed;
	}
	ft_printf_free(&flags, arg_ptr);
	return (total_printed);
}
