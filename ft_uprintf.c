/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:27:08 by jkrishna          #+#    #+#             */
/*   Updated: 2026/06/05 10:55:22 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numrec(unsigned int num)
{
	int	count;

	count = 0;
	if (num > 0)
		count += ft_numrec(num / 10);
	if (num > 0)
		count += write (1, &(char){num % 10 + '0'}, 1);
	return (count);
}

int	ft_uprintf(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		count += write (1, "0", 1);
		return (count);
	}
	count += ft_numrec(num);
	return (count);
}
