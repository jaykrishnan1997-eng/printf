/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:12:35 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/30 14:33:40 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sprintf(char *str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (!str)
	{
		count += ft_wrap(write(1, "(null)", 6));
		return (count);
	}
	while (str[j])
	{
		count += ft_wrap(write (1, &str[j], 1));
		j++;
	}
	return (count);
}
