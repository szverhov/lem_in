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

int	ft_atoi(const char *str)
{
	int					minus;
	unsigned long int	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
		&& (*str - '0') > 7)) && minus == 1)
			return (-1);
		if ((result > 922337203685477580 || (result == 922337203685477580
		&& (*str - '0') > 8)) && minus == -1)
			return (0);
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((int)(result * minus));
}

int	ft_return_1(char **tmp)
{
	int i;

	i = 0;
	if (g_err2 == 2)
	{
		while (g_str[i])
			i++;
		g_str[i - 1] = 0;
		while (g_str[i] != '\n')
		{
			g_str[i] = 0;
			i--;
		}
	}
	free(*tmp);
	return (1);
}
