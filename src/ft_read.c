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

void	ft_read_define(int fd)
{
	int		i;
	int		ret;
	char	input[1];

	i = 0;
	while ((ret = read(fd, input, 1)) && input[0] != '\n')
		if (input[0] >= '0' && input[0] <= '9')
			g_length = g_length * 10 + input[0] - '0';
		else
		{
			g_symbol[i] = input[0];
			i++;
		}
}

char	*ft_read_first_line(int fd)
{
	char	*str;
	char	input[1];
	int		ret;

	while ((ret = read(fd, input, 1)) && input[0] != '\n')
		str = ft_strcat(str, input[0]);
	str = ft_strcat(str, input[0]);
	g_width--;
	return (str);
}

int		ft_read_map(int fd, char *str, int ret, int *o_amount)
{
	int j;
	int k;

	j = 0;
	while (ret)
	{
		g_map[j] = malloc((g_width + 1) * sizeof(char));
		k = 0;
		while (str[k] != '\n')
		{
			if (str[k] == g_symbol[1])
				*o_amount = *o_amount + 1;
			if (str[k] != g_symbol[0] && str[k] != g_symbol[1])
				return (0);
			g_map[j][k] = str[k];
			k++;
		}
		if (k != g_width)
			return (0);
		g_map[j][k] = '\0';
		j++;
		ret = read(fd, str, g_width + 1);
		str[ret] = '\0';
	}
	return (1);
}

int		ft_read_input(char *path, int *o_amount)
{
	int		fd;
	int		ret;
	char	*str;

	g_width = 0;
	if (path)
		fd = open(path, O_RDWR);
	else
		fd = 0;
	if (fd < 0)
		return (0);
	ret = 1;
	ft_read_define(fd);
	if (g_length == 0 || g_symbol[2] == '\0')
	{
		printf("in");
		printf("l %i\n", g_length);
		printf("\ns %i\n", g_symbol[2] == '\0');
		return (0);
	}
	str = ft_read_first_line(fd);
	g_map = malloc((g_length + 1) * sizeof(char*));
	if (ft_read_map(fd, str, ret, o_amount) != 1)
		return (0);
	close(fd);
	if (fd < 0)
		return (0);
	return (1);
}
