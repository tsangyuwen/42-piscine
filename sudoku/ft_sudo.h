/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytseng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:13:40 by ytseng            #+#    #+#             */
/*   Updated: 2019/04/07 17:15:09 by ytseng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDO_H
# define FT_SUDO_H

# include <unistd.h>
# include <stdlib.h>

int		**g_sudo;
int		g_left;
int		**g_result;
int		g_check_sudo;

int		ft_solve_sudo(void);
void	ft_copy(void);
#endif
