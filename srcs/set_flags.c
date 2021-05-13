/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:13:28 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	set_flags(t_tag *tag, char *flags)
{
	if (tag && flags)
	{
		tag->alter = ft_strchr(flags, (int)'#') ? 1 : 0;
		tag->padding->zeroes = ft_strchr(flags, (int)'0') ? 1 : 0;
		tag->padding->neg_width = ft_strchr(flags, (int)'-') ? 1 : 0;
		tag->prefix->space = ft_strchr(flags, (int)' ') ? 1 : 0;
		tag->prefix->plus = ft_strchr(flags, (int)'+') ? 1 : 0;
	}
}
