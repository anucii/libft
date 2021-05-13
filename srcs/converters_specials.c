/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_specials.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:04:34 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	p_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;
	char			*base;

	base = HEXLO;
	input.llx = (unsigned long long int)va_arg(*pap, void *);
	ft_memdel(addr);
	*addr = (void *)(tag->to_out.uitoa)(input.llx, base);
}

void	pc_to_str(t_tag *tag, void **addr)
{
	if (tag && addr && tag->type == PC)
	{
		ft_memdel(addr);
		*addr = ft_strdup("%");
	}
}
