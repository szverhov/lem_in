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

static int	ft_try_to_make_int(char *str, int flag)
{
	char	*tmp;

	str++;
	if (!flag)
	{
		if (!ft_is_it_int(str))
			return (0);
		return (1);
	}
	if (!(tmp = ft_sub_str(str, ' ')))
		return (0);
	if (!ft_is_it_int(tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

static int	ft_roll_to_space(char *str, int *i, int flag)
{
	while (str[*i] != ' ' && str[*i] != '\0')
		*i += 1;
	if (flag)
		if (*i == '\0')
			return (0);
	return (1);
}

int			ft_check_double_space(char *str)
{
	int i;

	i = 0;
	if (!ft_roll_to_space(str, &i, 1))
		return (0);
	if (!(ft_try_to_make_int(&(*(str + i)), 1)))
		return (0);
	i++;
	if (!ft_roll_to_space(str, &i, 0))
		return (0);
	if (!(ft_try_to_make_int(&(*(str + i)), 0)))
		return (0);
	return (1);
}
