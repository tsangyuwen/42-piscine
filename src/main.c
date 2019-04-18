/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:41:06 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/17 10:41:07 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print(void)
{
	int j;
	int k;

	j = 0;
	while (g_map[j] != 0)
	{
		k = 0;
		while (g_map[j][k] != '\0')
		{
			write(1, &g_map[j][k], 1);
			k++;
		}
		write(1, "\n", 1);
		j++;
	}
}

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

void	ft_init(char *file, int o_amount)
{
	int check;

	g_map = 0;
	g_width = 0;
	g_length = 0;
	o_amount = 0;
	if (file)
		check = ft_read_input(file, &o_amount);
	else
		check = ft_read_input(0, &o_amount);
	if (g_length > 0 && g_width > 0)
		if (check != 0 && g_map != 0)
			ft_store_obstacle(o_amount);
		if (check != 0 && g_map != 0)
			ft_solve_square(o_amount);
		if (check != 0 && g_map != 0)
			ft_print();
	if (check == 0 || g_map == 0)
		write(1, "map error\n", 10);
}

int		main(int argc, char **argv)
{
	int o_amount;

	argv++;
	o_amount = 0;
	if (argc > 1)
		while (*argv)
		{
			ft_init(argv[0], o_amount);
			argv++;
		}
	else
		ft_init(0, o_amount);
	return (0);
}
