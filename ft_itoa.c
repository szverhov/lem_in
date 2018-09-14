/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:46:46 by szverhov          #+#    #+#             */
/*   Updated: 2017/10/28 15:34:07 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	n_len(unsigned int n, char minus)
{
	int res;

	res = 1;
	if (n == 0)
		return (2);
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (minus == '+' ? res : res + 1);
}

static char	*make_str(unsigned int n, char *res, int n_len, char minus)
{
	n_len--;
	res[n_len] = '\0';
	n_len--;
	while (n_len >= 0)
	{
		res[n_len] = n % 10 + 48;
		n = n / 10;
		n_len--;
	}
	if (minus == '-')
		res[0] = '-';
	return (res);
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	rem_n;
	char			minus;

	minus = '+';
	if (n == -2147483648)
	{
		rem_n = n;
		minus = '-';
	}
	else if (n < 0)
	{
		rem_n = n * -1;
		minus = '-';
	}
	else
		rem_n = n;
	res = (char*)malloc(sizeof(char) * (n_len(rem_n, minus) * 1));
	if (res == NULL)
		return (res);
	return (make_str(rem_n, res, n_len(rem_n, minus), minus));
}
