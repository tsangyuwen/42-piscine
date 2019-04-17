/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:28:05 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/15 15:02:19 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcat(char *str, char input)
{
	char	*comb;
	int		i;

	i = 0;
	g_width++;
	comb = (char*)malloc(sizeof(char) * (g_width + 1));
	while (g_width > 1 && str[i] != '\0')
	{
		comb[i] = str[i];
		i++;
	}
	if (g_width > 1)
		free(str);
	comb[g_width - 1] = input;
	comb[g_width] = '\0';
	return (comb);
}

void	ft_read_define(char input, int *i)
{
	if (input >= '0' && input <= '9')
		g_length = g_length * 10 + input - '0';
	else
	{
		g_symbol[*i] = input;
		*i = *i + 1;
	}
}

void	ft_read_input(char *file, int *o_amount)
{
	int		ret;
	int		fd;
	int		j;
	int		k;
	char	*str;
	char	input[1];

	fd = open(file, O_RDWR);
	if (fd < 0)
	{
		printf("open error");
		g_map = 0;
	}
	j = 0;
	while ((ret = read(fd, input, 1)) && input[0] != '\n')
		ft_read_define(input[0], &j);
	g_map = malloc((g_length + 1) * sizeof(char*));
	while ((ret = read(fd, input, 1)) && input[0] != '\n')
		str = ft_strcat(str, input[0]);
	str = ft_strcat(str, input[0]);
	g_width--;
	j = 0;
	while (ret)
	{
		g_map[j] = malloc((g_width + 1) * sizeof(char));
		k = 0;
		while (str[k] != '\0' && str[k] != '\n')
		{
			if (str[k] == g_symbol[1])
				*o_amount = *o_amount + 1;
			g_map[j][k] = str[k];
			k++;
		}
		g_map[j][k] = '\0';
		j++;
		ret = read(fd, str, g_width + 1);
		str[ret] = '\0';
	}
	g_map[j] = 0;
	if (close(fd) == -1)
	{
		printf("close error");
		g_map = 0;
	}
}

int		main(int argc, char **argv)
{
	int o_amount;

	argv++;
	if (argc > 1)
		while (*argv)
		{
			g_width = 0;
			o_amount = 0;
			ft_read_input(argv[0], &o_amount);
			if (g_map != 0)
				ft_fill_square(o_amount);
			if (g_map != 0)
				ft_print();
			argv++;
		}
	else
		printf("missing argument!");
	return (0);
}
