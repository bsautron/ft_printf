/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfo_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:53:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/17 04:05:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision(char *str, t_format *fg)
{
	char	*dst;
	int		prec;

	prec = fg->precision - ft_strlen(str);
	if (fg->conversion == 'p')
		prec += 1;
	if (!fg->flag->tag && ft_strequ(str, "0")
		&& fg->did_p && fg->precision == 0)
		dst = ft_strdup("");
	else if (prec >= 0)
		dst = ft_putprecision_ho(str, dst, prec, fg);
	else
		dst = ft_strdup(str);
	return (dst);
}

static char	*ft_flags(char *str, t_format *fg)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (i != ft_strlen(str))
	{
		if (fg->flag->tag && (fg->conversion == 'o' || fg->conversion == 'O') &&
				ft_strlen(str) > fg->precision)
			dst = ft_strjoin_per("0", str);
		else if ((fg->flag->tag && fg->conversion == 'x'))
			dst = ft_strjoin_per("0x", str);
		else if (fg->flag->tag && fg->conversion == 'X')
			dst = ft_strjoin_per("0X", str);
		else
			dst = str;
	}
	else
		dst = ft_strdup(str);
	return (dst);
}

static void	ft_zero(char *dst, char *str, t_format *fg)
{
	str[1] = '0';
	if (fg->conversion == 'x' || fg->conversion == 'p')
		dst[1] = 'x';
	else if (fg->conversion == 'X')
		dst[1] = 'X';
}

static char	*ft_width(char *str, t_format *fg)
{
	char	*dst;
	int		width;

	width = fg->width - ft_strlen(str);
	if (width >= 0)
	{
		dst = ft_strnew(width);
		if (fg->flag->zero && !fg->flag->left && !fg->did_p)
		{
			dst = ft_memset(dst, '0', width);
			if (((fg->conversion == 'x' || fg->conversion == 'X')
						&& fg->flag->tag && !ft_strequ(str, "0"))
					|| fg->conversion == 'p')
				ft_zero(dst, str, fg);
			dst = ft_strjoin_per(dst, str);
		}
		else if (fg->flag->left)
			dst = ft_strjoin_per(str, ft_memset(dst, ' ', width));
		else
			dst = ft_strjoin_per(ft_memset(dst, ' ', width), str);
	}
	else
		dst = ft_strdup(str);
	return (dst);
}

char		*ft_transfo_hexoct(char *str, t_format *fg)
{
	char	*dst;
	int		prec;

	if (fg->conversion == 'x' && fg->did_p
		&& fg->precision == 0 && ft_strequ(str, "0"))
		str = ft_strdup("");
	if (fg->conversion == 'p' && ft_strequ(str, "0") && fg->did_p)
		str = ft_strdup("0x");
	else if (fg->conversion == 'p')
		str = ft_strjoin("0x", str);
	dst = ft_precision(str, fg);
	dst = ft_flags(dst, fg);
	dst = ft_width(dst, fg);
	return (dst);
}
