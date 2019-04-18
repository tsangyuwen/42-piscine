/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:11:27 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/17 20:27:48 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_solve_square(int o_amount);
void	ft_print(void);
int		ft_read_input(char *path, int *o_amount);

int		g_length;
int		g_width;
int		**g_o_list;
char	g_symbol[4];
char	**g_map;

#endif
