/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:37:48 by jay-k             #+#    #+#             */
/*   Updated: 2026/06/05 10:55:22 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checker(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p'
		|| ch == 'd' || ch == 'i' || ch == 'u'
		|| ch == 'x' || ch == 'X' || ch == '%')
		return (1);
	return (0);
}

static int	ft_char_handler(const char *s, int *i, va_list *args)
{
	int	ret;

	if (s[*i] == '%' && ft_checker(s[*i + 1]))
	{
		ret = ft_channel(s[*i + 1], args);
		if (ret == -1)
			return (-1);
	}
	else
	{
		ret = (int)write(1, &s[*i], 1);
		if (ret == -1)
			return (-1);
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	int		ret;
	va_list	args;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		ret = ft_char_handler(s, &i, &args);
		if (ret == -1)
			return (va_end(args), -1);
		count += ret;
		if (s[i] == '%' && ft_checker(s[i + 1]))
			i++;
		i++;
	}
	va_end(args);
	return (count);
}
