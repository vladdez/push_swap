/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:28:17 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/17 14:36:12 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doviz(t_flg *f, t_stk **a, t_stk **b, char *line)
{
	if (f->v == 1 || f->c == 1)
	{
		ft_printf("\e[1;1H\e[2J");
		ft_printf("\n{yellow}STACK A:{eoc} ");
		printlist(*a);
		ft_printf("\n{blue}STACK B:{eoc} ");
		printlist(*b);
		if (f->c == 1)
			ft_printf("\n{red}current command: %s {eoc} \n", line);
		usleep(100000);
	}
}

void	check_viz(int ac, char **av, t_flg *f)
{
	if (ft_strcmp(av[ac - 1], "-c") == 0 || ft_strcmp(av[ac - 1], "-vc") == 0)
	{
		f->c = 1;
		free(av[ac]);
		av[ac - 1] = NULL;
	}
	else if (ft_strcmp(av[ac - 1], "-v") == 0)
	{
		f->v = 1;
		free(av[ac]);
		av[ac - 1] = NULL;
	}
}
