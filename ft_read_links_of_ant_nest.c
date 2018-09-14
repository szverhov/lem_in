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

int		ft_check_start_end(t_rooms *nest)
{
	int start;
	int end;

	start = 0;
	end = 0;
	while (nest->from)
		nest = nest->from;
	while (nest)
	{
		if (nest->start_r_end == 1)
			start++;
		if (nest->start_r_end == 2)
			end++;
		nest = nest->next;
	}
	if (start == 1 && end == 1)
		return (1);
	else
		return (0);
}

int		ft_read_links_of_ant_nest(t_rooms **nest, char *tmp)
{
	if (!nest || !(*nest))
		return (ft_free_return_zero(&tmp));
	if (!ft_check_and_link(&(*nest), tmp))
		return (ft_free_return_zero(&tmp));
	free(tmp);
	while (get_next_line(0, &tmp) > 0)
	{
		if (ft_strcmp(tmp, "##start") == 0 || ft_strcmp(tmp, "##end") == 0)
			return (ft_free_return_zero(&tmp));
		if (!stop_reading(tmp))
			return (ft_return_1(&tmp));
		ft_add_to_gstr(tmp);
		if (tmp[0] == '#' && ft_strcmp(tmp, "##start")
		!= 0 && ft_strcmp(tmp, "##end") != 0)
		{
			free(tmp);
			continue ;
		}
		if (!(g_err2 = ft_check_and_link(&(*nest), tmp)))
			ft_free_return_zero(&tmp);
		else if (g_err2 == 2)
			return (ft_return_1(&tmp));
		free(tmp);
	}
	return (1);
}
