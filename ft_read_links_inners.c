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

int		ft_link_it(t_rooms **from, t_rooms **to, char *name1)
{
	t_links *tmp;

	if (!((*from)->links))
	{
		if (!((*from)->links = (t_links*)malloc(sizeof(t_links))))
			return (0);
		if (!((*from)->links->name = ft_inner_substr(name1, '\0')))
			return (0);
		(*from)->links->room = (*to);
		(*from)->links->next = 0;
		return (1);
	}
	tmp = (*from)->links;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_links*)malloc(sizeof(t_links))))
		return (0);
	if (!(tmp->next->name = ft_inner_substr(name1, '\0')))
		return (0);
	tmp->next->room = (*to);
	tmp->next->next = 0;
	return (1);
}

int		ft_check_is_linked(t_rooms *from, t_rooms *to)
{
	t_links *tmp;

	tmp = from->links;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, to->name) == 0)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_linking(t_rooms **nest, char *name1, char *name2)
{
	t_rooms *i;
	t_rooms *j;

	i = (*nest);
	j = (*nest);
	if (!(ft_find_links(&i, name1)))
		return (3);
	if (!(ft_find_links(&j, name2)))
		return (3);
	if (ft_check_is_linked(i, j) == 0)
		if (!ft_link_it(&i, &j, name1))
			return (0);
	if (ft_check_is_linked(j, i) == 0)
		if (!ft_link_it(&j, &i, name2))
			return (0);
	return (1);
}

int		ft_try_to_link(t_rooms **nest, char *tmp)
{
	char	*name1;
	char	*name2;
	int		err;

	if (!ft_init_names(tmp, &name1, &name2))
		return (0);
	if (ft_strcmp(name1, name2) == 0)
	{
		ft_free_strs(&name1, &name2);
		return (2);
	}
	if ((err = ft_linking(&(*nest), name1, name2)) == 0)
	{
		ft_free_strs(&name1, &name2);
		return (0);
	}
	else if (err == 3)
	{
		ft_free_strs(&name1, &name2);
		return (2);
	}
	ft_free_strs(&name1, &name2);
	return (1);
}

int		ft_check_and_link(t_rooms **nest, char *tmp)
{
	int minus;
	int err;

	if (!(minus = ft_count_of_minuses(tmp)))
		return (0);
	if (minus == 1)
	{
		if (!(err = ft_try_to_link(&(*nest), tmp)))
			return (0);
		else if (err == 2)
			return (2);
	}
	else
		return (0);
	return (1);
}
