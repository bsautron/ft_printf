/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_per_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:48:56 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/17 18:49:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_per_aux(const char *s1, const char *s2)
{
	int		len_all;
	char	*dst;

	if (s1 && s2)
	{
		len_all = ft_strlen_per(s1) + ft_strlen(s2);
		dst = ft_memalloc(len_all + 1);
		if (dst)
		{
			ft_strncpy(dst, s1, ft_strlen_per(s1));
			ft_strncat(dst, s2, ft_strlen(s2));
			return (dst);
		}
	}
	return (NULL);
}
