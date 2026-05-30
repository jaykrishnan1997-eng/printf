/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay-k <jay-k@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:24:32 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/07 20:10:14 by jay-k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numrec(long num)
{
	int	count;

	count = 0;
	if (num > 0)
		count += ft_numrec(num / 10);
	if (num > 0)
		count += write (1, &(char){num % 10 + '0'}, 1);
	return (count);
}

int	ft_diprintf(int num)
{
	int		count;
	long	lnum;

	count = 0;
	lnum = (long)num;
	if (lnum == 0)
	{
		count += write (1, "0", 1);
		return (count);
	}
	else if (lnum < 0)
	{
		lnum = -lnum;
		count += write (1, "-", 1);
	}
	count += ft_numrec(lnum);
	return (count);
}
