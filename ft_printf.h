/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:41:53 by jkrishna          #+#    #+#             */
/*   Updated: 2026/06/05 10:55:22 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(const char *s, ...);
int	ft_channel(char a, va_list *args);
int	ft_cprintf(int c);
int	ft_sprintf(char *str);
int	ft_pprintf(void *ptr);
int	ft_diprintf(int num);
int	ft_uprintf(unsigned int num);
int	ft_xprintf(unsigned int num);
int	ft_cxprintf(unsigned int num);
int	ft_percprintf(void);
int	ft_write(int write);

#endif