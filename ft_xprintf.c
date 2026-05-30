/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:22:50 by jay-k             #+#    #+#             */
/*   Updated: 2026/05/30 14:33:40 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexe(unsigned int num)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		count += hexe(num / 16);
	count += ft_wrap(write (1, &hex[num % 16], 1));
	return (count);
}

int	ft_xprintf(unsigned int num)
{
	int	count;

	if (num == 0)
		return (ft_wrap(write(1, "0", 1)));
	count = 0;
	count += hexe(num);
	return (count);
}
