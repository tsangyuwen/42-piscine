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

void	ft_print(char **c)
{
	int j;
	int k;

	j = 0;
	while (c[j] != 0)
	{
		k = 0;
		while (c[j][k] != '\0')
		{
			printf("%c", c[j][k]);
			k++;
		}
		printf("\n");
		j++;
	}
}

char	*ft_strcat(char *str, char *input)
{
	char	*comb;
	int		i;

	i = 0;
	comb = (char*)malloc(sizeof(char) * (g_width + 1));
	while (g_width > 0 && str[i] != '\0')
	{
		comb[i] = str[i];
		i++;
	}
	comb[g_width] = input[0];
	comb[g_width + 1] = '\0';
	return (comb);
}

char	**ft_read_input(char *file)
{
	int		ret;
	int		fd;
	int		i;
	int		m;
	int		j;
	int		k;
	char	*str;
	char	input[1];
	char	**c;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (0);
    i = 0;
    while ((ret = read(fd, input, 1)) && input[0] != '\n')
    {
        if (input[0] >='0' && input[0] <= '9')
            g_length = g_length *  10 + input[0] - '0';
        else
        {
            g_symbol[i] = input[0];
            i++;
        }
    }
    g_width = 0;
    while ((ret = read(fd, input, 1)) && input[0] != '\n')
    {
    	str = ft_strcat(str, input);
    	g_width++;
    }
    str = ft_strcat(str, input);
    c = malloc((g_length + 1) * sizeof(char*));
    j = 0;
    while (ret)
    {
    	c[j] = malloc((g_width + 1) * sizeof(char));
    	k = 0;
    	while (str[k] != '\0' && str[k] != '\n')
    	{
    		c[j][k] = str[k];
    		k++;
    	}
    	c[j][k] = '\0';
    	j++;
    	ret = read(fd, str, g_width + 1);
    	str[ret] = '\0';
    }
    c[j] = 0;
    return (c);
}

int		main(int argc, char **argv)
{
	char	**c;
	int		i;

	argv++;
	if (argc > 1)
		while (*argv)
		{
			c = ft_read_input(argv[0]);
			c = ft_fill_square(c);
			if (c == 0)
				return (0);
			ft_print(c);
			argv++;
		}
	else
		printf("error");
	return (0);
}
