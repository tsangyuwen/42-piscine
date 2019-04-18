/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:12:43 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/07 17:12:45 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudo.h"
#include <stdio.h>

int		ft_valid_square(int j, int k)
{
	int sj;
	int sk;

	sj = 0;
	while (sj < 3)
	{
		sk = 0;
		while (sk < 3 && j != (j / 3) * 3 + sj && k != (k / 3) * 3 + sk)
		{
			if (g_sudo[j][k] == g_sudo[(j / 3) * 3 + sj][(k / 3) * 3 + sk])
				return (0);
			sk++;
		}
		sj++;
	}
	return (1);
}

int		ft_validcheck(void)
{
	int j;
	int k;
	int i;

	j = -1;
	while (j++ < 8)
	{
		k = -1;
		while (k++ < 8)
			if (g_sudo[j][k] != 0)
			{
				i = -1;
				while (i++ < 8)
				{
					if (g_sudo[j][k] == g_sudo[j][i] && i != k)
						return (0);
					if (g_sudo[j][k] == g_sudo[i][k] && i != j)
						return (0);
				}
				if (ft_valid_square(j, k) == 0)
					return (0);
			}
	}
	return (1);
}

int		ft_create_sudo(char **argv)
{
	int j;
	int k;

	g_sudo = (int **)malloc(sizeof(int *) * 9);
	j = -1;
	while (j++ < 8)
	{
		g_sudo[j] = (int *)malloc(sizeof(int) * 9);
		k = -1;
		while (k++ < 8)
		{
			if (argv[j][k] == '.')
			{
				g_left++;
				g_sudo[j][k] = 0;
			}
			else if (argv[j][k] >= '0' && argv[j][k] <= '9')
				g_sudo[j][k] = argv[j][k] - '0';
			else
				return (0);
		}
		if (argv[j][k] != '\0')
			return (0);
	}
	return (1);
}

void	ft_print_sudo(void)
{
	int		j;
	int		k;
	char	c;

	j = 0;
	while (j < 9)
	{
		k = 0;
		while (k < 9)
		{
			c = g_result[j][k] + '0';
			write(1, &c, 1);
			if (k != 8)
				write(1, " ", 1);
			k++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	int check;

	argv++;
	g_left = 0;
	if (argc != 10)
	{
		printf("missing argument\n");
		return (0);
	}
	check = ft_create_sudo(argv);
	if (check == 0)
	{
		printf("can't create\n");
		return (0);
	}
	check = ft_validcheck();
	if (check == 0)
	{
		write(1, "ERROR: not a valid sudoku!\n", 27);
		return (0);
	}
	check = ft_solve_sudo();
	if (check == 0)
	{
		write(1, "ERROR: no valid solution!\n", 26);
		return (0);
	}
	else
		ft_print_sudo();
	return (0);
}
