/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:07:10 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	launch_conversion(t_tag *tag, va_list *pap, void **addr)
{
	char	*check;

	if (tag && pap && addr)
	{
		check = (char *)*addr;
		preset_conversion(tag, check);
		ft_convert(pap, tag, addr);
		ft_format(tag, addr);
	}
}
