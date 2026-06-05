/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cxprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:20:12 by jay-k             #+#    #+#             */
/*   Updated: 2026/06/05 10:55:22 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexe(unsigned int num)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
		count += hexe(num / 16);
	count += write (1, &hex[num % 16], 1);
	return (count);
}

int	ft_cxprintf(unsigned int num)
{
	int	count;

	if (num == 0)
		return (write(1, "0", 1));
	count = 0;
	count += hexe(num);
	return (count);
}
