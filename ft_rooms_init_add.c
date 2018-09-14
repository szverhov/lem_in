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

int		ft_init_first(t_rooms **start, char *str, int count_of_ants)
{
	if (!((*start) = (t_rooms*)malloc(sizeof(t_rooms))))
		return (0);
	if (!((*start)->name = ft_sub_str(str, ' ')))
		return (0);
	(*start)->count_ants = count_of_ants;
	(*start)->from = 0;
	(*start)->was = 0;
	if (count_of_ants == 0)
		(*start)->start_r_end = 0;
	else if (count_of_ants > 0)
		(*start)->start_r_end = 1;
	else if (count_of_ants == -1)
	{
		(*start)->count_ants = 0;
		(*start)->start_r_end = 2;
	}
	(*start)->links = 0;
	(*start)->next = 0;
	return (1);
}

int		ft_check_names_matches(t_rooms *rooms, char *name)
{
	char *tmp;

	tmp = ft_sub_str(name, ' ');
	if (rooms)
		while (rooms)
		{
			if (ft_strcmp(rooms->name, tmp) == 0)
			{
				free(tmp);
				return (0);
			}
			rooms = rooms->next;
		}
	free(tmp);
	tmp = 0;
	return (1);
}

int		ft_add_rooms(t_rooms **start, char *str, int count_of_ants)
{
	t_rooms *tmp;

	tmp = (*start);
	if (!ft_check_names_matches((*start), str))
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_rooms*)malloc((sizeof(t_rooms)))))
		return (0);
	tmp->next->name = ft_sub_str(str, ' ');
	tmp->next->was = 0;
	tmp->next->count_ants = count_of_ants;
	tmp->next->from = 0;
	if (count_of_ants > 0)
		tmp->next->start_r_end = 1;
	else if (count_of_ants == 0)
		tmp->next->start_r_end = 0;
	else if (count_of_ants == -1)
	{
		tmp->next->count_ants = 0;
		tmp->next->start_r_end = 2;
	}
	tmp->next->links = 0;
	tmp->next->next = 0;
	return (1);
}
