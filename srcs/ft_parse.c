/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:43:21 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
_Bool		ft_parse(t_tag *tag, char *s)
{
	if (!s)
		return (1);
	s++;
	if (*s == '%')
		return (1);
	if (check_flags(tag, &s))
		if (check_width(tag, &s))
			if (check_prec(tag, &s))
				if (check_length(&s))
					if (tagend(*s))
						return (1);
	return (0);
}
