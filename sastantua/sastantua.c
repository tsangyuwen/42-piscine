/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 09:27:22 by ytseng            #+#    #+#             */
/*   Updated: 2019/03/31 13:18:44 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_symbol(int number, char c)
{
	int i;

	i = 0;
	while (i++ < number)
		ft_putchar(c);
}

void	ft_print_door(int size, int star)
{
	int i;
	int s;

	i = 0;
	s = size + 1;
	while (i <= size)
	{
		ft_print_symbol(s = size - i, ' ');
		ft_putchar('/');
		ft_print_symbol((star - size) / 2, '*');
		s = size + 1;
		while (s-- > 0)
		{
			if (size > 3 && i == size / 2 && s == 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		ft_print_symbol((star - size) / 2, '*');
		ft_putchar('\\');
		ft_putchar('\n');
		star += 2;
		i++;
	}
}

int		ft_print_upper_sas(int space, int size, int star)
{
	int i;
	int tier_height;

	i = 0;
	while (i++ <= size)
	{
		tier_height = i + 2;
		if (i == size)
			tier_height = 3 - size % 2;
		while (tier_height--)
		{
			ft_print_symbol(space, ' ');
			ft_putchar('/');
			ft_print_symbol(star, '*');
			ft_putchar('\\');
			ft_putchar('\n');
			space--;
			star += 2;
		}
		if (i == size)
			return (star);
		space = space - (((i - 1) / 2) + 2);
		star = star + (((i - 1) / 2) + 2) * 2;
	}
	return (star);
}

int		ft_cal_first_space(int size)
{
	int space;

	space = 0;
	while (size > 0)
	{
		space = space + size + 2;
		if (size > 1)
			space = space + size / 2 + 1;
		size--;
	}
	return (space--);
}

void	sastantua(int size)
{
	int star;
	int space;
	int t;

	t = size;
	star = 1;
	if (size < 1)
		return ;
	space = ft_cal_first_space(size) - 1;
	star = ft_print_upper_sas(space, size, star);
	space = size + 1;
	ft_print_door(size - 2 + size % 2, star);
}
