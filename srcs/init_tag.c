/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:31:09 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	preset_conversion(t_tag *tag, char *s)
{
	if (!(tag && s))
		return ;
	tag->type = get_type(s);
	tag->to_out = get_action(tag->type);
	tag->null_val = 0;
}

void	ft_reinit_tag(t_tag *tag)
{
	if (!tag)
		return ;
	tag->type = 0;
	tag->to_out.err = NULL;
	tag->width = 0;
	tag->precision = -1;
	tag->alter = 0;
	tag->padding = (t_padding *)ft_memset((void *)tag->padding, 0, \
				sizeof(t_padding));
	tag->prefix = (t_prefix *)ft_memset((void *)tag->prefix, 0, \
				sizeof(t_prefix));
	tag->null_val = 0;
}

t_tag	*init_tag(void)
{
	t_tag	*ret;

	if ((ret = (t_tag *)ft_memalloc(sizeof(t_tag))))
	{
		if (!(ret->padding = (t_padding *)ft_memalloc(sizeof(t_padding))))
			exit(EXIT_FAILURE);
		ret->padding = (t_padding *)ft_memset((void *)ret->padding, 0, \
				sizeof(t_padding));
		if (!(ret->prefix = (t_prefix *)ft_memalloc(sizeof(t_prefix))))
			exit(EXIT_FAILURE);
		ret->prefix = (t_prefix *)ft_memset((void *)ret->prefix, 0, \
				sizeof(t_prefix));
		return (ret);
	}
	exit(EXIT_FAILURE);
}

void	ft_clean_tag(t_tag *tag)
{
	if (!tag)
		return ;
	ft_memdel((void **)&(tag->padding));
	ft_memdel((void **)&(tag->prefix));
	ft_memdel((void **)&tag);
}
