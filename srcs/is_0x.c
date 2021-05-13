/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_0x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:17:46 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
_Bool	is_0x(t_tag *tag)
{
	if (tag->type == P || ((tag->type >= X && tag->type <= ZXX) && tag->alter\
				&& !(tag->null_val)))
		return (1);
	return (0);
}
