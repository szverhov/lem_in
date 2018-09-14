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

int		ft_there_is_space(char *str1, char *str2)
{
	int i;
	int j;
	int res1;
	int res2;

	i = -1;
	j = -1;
	res1 = 0;
	res2 = 0;
	while (str1[++i])
		if (str1[i] == ' ')
			res1 = 1;
	while (str2[++j])
		if (str1[j] == ' ')
			res2 = 1;
	if (res1 == 1 && res2 == 1)
		return (1);
	return (0);
}

int		ft_coords(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (g_str[i] != 0)
	{
		j = 0;
		while (g_str[i] != ' ' && g_str[i] != 0)
			i++;
		i++;
		while (str[j] != ' ' && str[j] != 0)
			j++;
		j++;
		tmp = ft_sub_str(g_str + i, '\n');
		if (tmp == 0)
			return (1);
		if (ft_there_is_space(tmp, str + j) && ft_strcmp(tmp, str + j) == 0)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}
