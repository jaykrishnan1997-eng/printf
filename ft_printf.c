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

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count += ft_channel(s[i + 1], &args);
			i++;
		}
		else
			count += ft_write(write (1, &s[i], 1));
		i++;
	}
	va_end (args);
	return (count);
}
