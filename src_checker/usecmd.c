/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usecmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:51:49 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/17 14:51:52 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usecmd2(t_stk **a, t_stk **b, char *line)
{
	if (ft_strcmp(line, "rr") == 0)
	{
		ft_r(a);
		ft_r(b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		ft_rr(a);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rr(b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rr(a);
		ft_rr(b);
	}
}

void	usecmd(t_stk **a, t_stk **b, char *line)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "sa") == 0)
		ft_s(*a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_s(*b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_s(*a);
		ft_s(*b);
	}
	else if (ft_strcmp(line, "pa") == 0)
		ft_p(b, a, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_p(a, b, 1);
	else if (ft_strcmp(line, "ra") == 0)
		ft_r(a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_r(b);
	else
		usecmd2(a, b, line);
}
