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
	if (a == 'c')
		return (ft_cprintf(va_arg(*args, int)));
	else if (a == 's')
		return (ft_sprintf(va_arg(*args, char *)));
	else if (a == 'p')
		return (ft_pprintf(va_arg(*args, void *)));
	else if (a == 'd')
		return (ft_diprintf(va_arg(*args, int)));
	else if (a == 'i')
		return (ft_diprintf(va_arg(*args, int)));
	else if (a == 'u')
		return (ft_uprintf(va_arg(*args, unsigned int)));
	else if (a == 'x')
		return (ft_xprintf(va_arg(*args, unsigned int)));
	else if (a == 'X')
		return (ft_cxprintf(va_arg(*args, unsigned int)));
	else if (a == '%')
		return (ft_percprintf());
	else
		return (0);
}
