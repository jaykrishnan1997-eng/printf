/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:47:04 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/30 14:33:57 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cprintf(int c)
{
	int	count;

	count = ft_wrap(write (1, &c, 1));
	if (count < 0)
		return (0);
	return (count);
}
