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

int	ft_clean_nest(t_rooms **nest)
{
	t_rooms *tmp;
	t_links *ltmp;

	if (g_err != 5)
		write(1, "ERROR\n", 6);
	get_next_line(-1234, 0);
	free(g_str);
	if (*nest)
		while ((*nest)->from)
			(*nest) = (*nest)->from;
	while ((*nest))
	{
		tmp = (*nest);
		while ((*nest)->links)
		{
			ltmp = (*nest)->links;
			(*nest)->links = (*nest)->links->next;
			free(ltmp->name);
			free(ltmp);
		}
		(*nest) = (*nest)->next;
		free(tmp->name);
		free(tmp);
	}
	return (0);
}
