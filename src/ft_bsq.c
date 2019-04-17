/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:04:33 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/15 15:21:52 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_store_obstacle(int o_amount)
{
	int j;
	int k;

	g_o_list = (int **)malloc((o_amount + 1) * sizeof(int *));
	while (o_amount--)
		g_o_list[o_amount] = (int *)malloc(2 * sizeof(int));
	o_amount++;
	j = 0;
	while (g_map[j] != 0)
	{
		k = 0;
		while (g_map[j][k] != '\0')
		{
			if (g_map[j][k] == g_symbol[1])
			{
				g_o_list[o_amount][0] = j;
				g_o_list[o_amount][1] = k;
				o_amount++;
			}
			k++;
		}
		j++;
	}
	g_o_list[o_amount] = 0;
}

int		ft_check_square(int t, int l, int r, int *check)
{
	int		i;
	int		b;
	int		*o;

	b = t + r - l;
	i = 0;
	while (g_o_list[i] != 0 && (o = g_o_list[i]))
	{
		if (t == 0 || (o[1] >= l && o[1] <= r && o[0] == t - 1))
			check[0] = 1;
		if (l == 0 || (o[1] == l - 1 && o[0] >= t && o[0] <= b))
			check[1] = 1;
		if (r == g_width - 1 || (o[1] == r + 1 && o[0] >= t && o[0] <= b))
			check[2] = 1;
		if (b == g_length - 1 || (o[1] >= l && o[1] <= r && o[0] == b + 1))
			check[3] = 1;
		if (check[0] == 1 && check[1] == 1 && check[2] == 1 && check[3] == 1)
			return (2);
		if (o[1] == r && o[0] == b)
			return (0);
		i++;
	}
	if (check[2] == 1 || check[3] == 1)
		return (0);
	return (1);
}

int		ft_find_square(int j, int *k)
{
	int		check;
	int		square;
	int		right;
	int		*check_list;

	check = 1;
	square = 1;
	while (check == 1)
	{
		check_list = malloc(4 * sizeof(char));
		check_list[0] = '0';
		check_list[1] = '0';
		check_list[2] = '0';
		check_list[3] = '0';
		right = square + *k - 1;
		if (right > g_width || j + *k - right > g_length)
			return (0);
		check = ft_check_square(j, *k, right, check_list);
		square++;
		free(check_list);
	}
	if (check == 0)
		return (0);
	*k = *k + square - 1;
	return (square - 1);
}

void	ft_find_max_square(int *max)
{
	int j;
	int k;
	int max_k;
	int max_j;
	int square;

	j = 0;
	while (g_map[j] != 0 && j < g_length - *max)
	{
		k = 0;
		while (g_map[j][k] != '\0' && k < g_width - *max)
		{
			if (g_map[j][k] != g_symbol[1])
				if (*max < (square = ft_find_square(j, &k)))
				{
					*max = square;
					max_j = j;
					max_k = k - *max;
				}
			k++;
		}
		j++;
	}
	g_length = max_j;
	g_width = max_k;
}

void	ft_fill_square(int o_amount)
{
	int		max;
	int		j;
	int		k;
	char	*t;

	ft_store_obstacle(o_amount);
	max = 0;
	ft_find_max_square(&max);
	if (max == 0)
		g_map = 0;
	j = g_length;
	k = g_width;
	while (j < g_length + max)
	{
		k = g_width;
		while (k < g_width + max)
		{
			g_map[j][k] = g_symbol[2];
			k++;
		}
		j++;
	}
}
