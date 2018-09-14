/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:31:43 by szverhov          #+#    #+#             */
/*   Updated: 2017/11/03 12:23:59 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_start_to_head(t_rooms **start)
{
	t_rooms *tmp;
	t_rooms *tmp2;

	tmp = *start;
	if (tmp->start_r_end != 2)
	{
		while (tmp)
		{
			if (tmp->next->start_r_end == 2)
				break ;
			tmp = tmp->next;
		}
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp2->next = (*start);
		(*start) = tmp2;
	}
}

void		ft_end_to_tail(t_rooms **end)
{
	t_rooms *tmp;
	t_rooms *tmp2;

	tmp = *end;
	while (tmp)
	{
		if (tmp->next->start_r_end == 1)
			break ;
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = 0;
}

void		ft_find_path(t_rooms *start, t_links *link)
{
	while (start)
	{
		while (link)
		{
			if (link->room->was == 0 || link->room->was > (start)->was + 1)
			{
				link->room->was = start->was + 1;
				link->room->from = start;
				ft_find_path(link->room, link->room->links);
			}
			link = link->next;
		}
		start = start->next;
	}
}

int			ft_make_path(t_rooms *start)
{
	t_rooms *tmp;

	ft_start_to_head(&start);
	ft_end_to_tail(&start);
	ft_find_path(start, start->links);
	start->from = 0;
	tmp = start;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->from == 0)
	{
		ft_clean_nest(&start);
		exit(0);
	}
	write(1, g_str, ft_strlen(g_str));
	write(1, "\n", 1);
	return (1);
}
