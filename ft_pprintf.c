/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay-k <jay-k@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:00:08 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/07 20:07:59 by jay-k            ###   ########.fr       */
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
	count += write (1, &hex[num % 16], 1);
	return (count);
}

int	ft_pprintf(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count = write (1, "0x", 2);
	count += hexe((unsigned long)ptr);
	return (count);
}
