/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:23:52 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/07 13:23:53 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudo.h"
#include <stdio.h>

void	ft_print_sudo(void);

void	ft_mark_square(int row, int col, int *mark)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < 3)
	{
		while (k < 3)
		{
			mark[g_sudo[(row / 3) * 3 + j][(col / 3) * 3 + k]] = 1;
			k++;
		}
		j++;
		k = 0;
	}
}

int		ft_mark_exist(int row, int col, int *mark)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (i++ < 9)
		mark[i] = 0;
	i = -1;
	while (i++ < 8)
	{
		mark[g_sudo[i][col]] = 1;
		mark[g_sudo[row][i]] = 1;
	}
	ft_mark_square(row, col, mark);
	i = 0;
	while (i++ < 9)
		if (mark[i] == 0)
			count++;
	return (count);
}

int		ft_find_smallest_count(int *minj, int *mink, int *mark)
{
	int j;
	int k;
	int mincount;
	int count;

	mincount = 10;
	j = -1;
	while (j++ < 8)
	{
		k = -1;
		while (k++ < 8)
			if (g_sudo[j][k] == 0)
			{
				count = ft_mark_exist(j, k, mark);
				if (count == 0)
					return (0);
				if (count < mincount)
				{
					mincount = count;
					*minj = j;
					*mink = k;
				}
			}
	}
	return (1);
}

void	ft_copy(void)
{
	int	j;
	int	k;

	g_result = (int **)malloc(sizeof(int *) * 9);
	j = -1;
	while (j++ < 8)
	{
		g_result[j] = (int *)malloc(sizeof(int) * 9);
		k = -1;
		while (k++ < 8)
		{
			g_result[j][k] = g_sudo[j][k];
		}
	}
	g_check_sudo++;
}

int		ft_solve_sudo(void)
{
	int minj;
	int mink;
	int mark[10];
	int i;

	minj = 0;
	mink = 0;
	if (ft_find_smallest_count(&minj, &mink, mark) == 0)
		return (0);
	ft_mark_exist(minj, mink, mark);
	i = 0;
	while (i++ < 9)
		if (mark[i] == 0)
		{
			g_sudo[minj][mink] = i;
			g_left--;
			ft_solve_sudo();
			if (g_left == 0)
			{
				ft_copy();
			}
			g_sudo[minj][mink] = 0;
			g_left++;
		}
	if (g_check_sudo >= 2)
		return (0);
	else if (g_check_sudo == 1)
		return (1);
	else
		return (0);
}
