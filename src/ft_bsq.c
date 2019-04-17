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

int		**ft_store_obstacle(char **c, int o)
{
	int j;
	int k;
	int i;
	int **n;

	n = (int **)malloc(150 * sizeof(int *));
	i = -1;
	while (150 > i++)
		n[i] = (int *)malloc(2 * sizeof(int));
	j = 0;
	i = 0;
	while (c[j] != 0)
	{
		k = 0;
		while (c[j][k] != '\0')
		{
			if (c[j][k] == g_symbol[1])
			{
				n[i][0] = j;
				n[i][1] = k;
				i++;
			}
			k++;
		}
		j++;
	}
	n[i] = 0;
	return (n);
}

int		ft_check_square(int top, int left, int right, int **n)
{
	int		i;
	int		bottom;
	char	*check;

	check = malloc(4 * sizeof(char));
	bottom = top + right - left;
	i = 0;
	if (right > g_width || bottom > g_length)
	    return (0);
	while (n[i] != 0)
	{
		if (top == 0 || (n[i][1] >= left && n[i][1] <= right && n[i][0] == top - 1))
			check[0] = 1;
		if (left == 0 || (n[i][1] == left - 1 && n[i][0] >= top && n[i][0] <= bottom))
			check[1] = 1;
		if (right == g_width - 1 || (n[i][1] == right + 1 && n[i][0] >= top && n[i][0] <= bottom))
			check[2] = 1;
		if (bottom == g_length - 1 || (n[i][1] >= left && n[i][1] <= right && n[i][0] == bottom + 1))
			check[3] = 1;
		i++;
	}
	if (check[0] == 1 && check[1] == 1 && check[2] == 1 && check[3] == 1)
		return (2);
	if (check[2] == 1 || check[3] == 1)
		return (0);
	return (1);
}

int		ft_find_square(int j, int *k, int **n)
{
	int check;
	int square;

	check = 1;
	square = 1;
	while (check == 1)
	{
		check = ft_check_square(j, *k, square + *k - 1, n);
		//printf("check %i\n", check);
		if (check == 0)
		{
		    *k = *k + square;
			return (0);
		}
		square++;
	}
	*k = *k + square - 1;
	//printf("square %i\n", square);
	return (square - 1);
}

int 	ft_find_max_square(char **c, int ***n)
{
	int j;
	int k;
	int max;
	int max_k;
	int max_j;
	int square;

	j = 0;
	max = 0;
	while (c[j] != 0)
	{
		k = 0;
		while (c[j][k] != '\0')
		{
			if (c[j][k] != 'o')
			{
			    square = ft_find_square(j, &k, *n);
				if (max < square)
				{
				    max = square;
					max_j = j;
					max_k = k - max;
				}
			}
			k++;
		}
		j++;
	}
	g_length = max_j;
	g_width = max_k;
	return (max);
}

char	**ft_fill_square(char **c)
{
	int o = 10;
	int **n;
	int max;
	int j;
	int k;
	char *t;

	n = ft_store_obstacle(c, o);
	max = ft_find_max_square(c, &n);
	if (max == 0)
		return (0);
	j = g_length;
	k = g_width;
	while (j < g_length + max)
    {
        k = g_width;
        while (k < g_width + max)
        {
            c[j][k] = g_symbol[2];
            k++;
        }
        j++;
    }
	return (c);
}
