/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:00:08 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/30 14:33:40 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexe(unsigned long num)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		count += hexe(num / 16);
	count += ft_wrap(write (1, &hex[num % 16], 1));
	return (count);
}

int	ft_pprintf(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += ft_wrap(write(1, "(nil)", 5));
		return (count);
	}
	count = ft_wrap(write (1, "0x", 2));
	count += hexe((unsigned long)ptr);
	return (count);
}
