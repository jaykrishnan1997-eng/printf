/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_channel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:02:37 by jay-k             #+#    #+#             */
/*   Updated: 2026/06/05 13:01:00 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_channel(char a, va_list *args)
{
	int	count;

	count = 0;
	if (a == 'c')
		count += ft_cprintf(va_arg(*args, int));
	else if (a == 's')
		count += ft_sprintf(va_arg(*args, char *));
	else if (a == 'p')
		count += ft_pprintf(va_arg(*args, void *));
	else if (a == 'd')
		count += ft_diprintf(va_arg(*args, int));
	else if (a == 'i')
		count += ft_diprintf(va_arg(*args, int));
	else if (a == 'u')
		count += ft_uprintf(va_arg(*args, unsigned int));
	else if (a == 'x')
		count += ft_xprintf(va_arg(*args, unsigned int));
	else if (a == 'X')
		count += ft_cxprintf(va_arg(*args, unsigned int));
	else if (a == '%')
		count += ft_percprintf();
	else
		return (0);
	return (count);
}
