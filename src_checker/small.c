/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:57:08 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/24 13:26:10 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parted_a_brute2(t_stk **a, t_stk **str, t_stk **b)
{
	int		max;
	int		min;

	max = findmax(*a);
	min = findmin(*a);
	while (ft_list_size(*a) != 3)
	{
		if ((*a)->num != min && (*a)->num != max)
			push_cmd(str, a, b, -4);
		else
			push_cmd(str, a, b, 3);
	}
	case3(a, str);
}

void	parted_a_brute(t_stk **a, t_stk **str, t_stk **b)
{
	int		len;
	int		pivota;
	int		i;
	int		max;
	int		min;

	max = findmax(*a);
	min = findmin(*a);
	i = 0;
	pivota = findpivot(a, 0);
	len = ft_list_size(*a);
	i = (len / 2);
	while (i != 1)
	{
		if ((*a)->num < pivota && (*a)->num != min && (*a)->num != max)
		{
			push_cmd(str, a, b, -4);
			i--;
		}
		else
			push_cmd(str, a, b, 3);
	}
	parted_a_brute2(a, str, b);
}

void	casesmall(t_stk **a, t_stk **str, t_stk **b)
{
	int		i;
	int		step;

	parted_a_brute(a, str, b);
	comb_lock(a, str, b);
	i = findmin(*a);
	step = findmin2(*a);
	if (step < (ft_list_size(*a) / 2))
	{
		while ((*a)->num != i)
			push_cmd(str, a, b, 2);
	}
	else
	{
		while ((*a)->num != i)
			push_cmd(str, a, b, 3);
	}
}
