/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:53:07 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 15:53:10 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_of_a(t_stk **a, t_stk **str, t_stk **b)
{
	int		len;
	int		pivota;
	int		chunk;
	int		j;

	j = 0;
	chunk = 2;
	pivota = 0;
	len = 0;
	while (ft_list_size(*a) > 5)
	{
		pivota = findpivot(a, 0);
		len = ft_list_size(*a);
		while (pivchecker(a, pivota) != 1)
		{
			if ((*a)->num < pivota)
			{
				push_cmd(str, a, b, -4);
				(*b)->chunk = chunk;
			}
			else
				push_cmd(str, a, b, 3);
		}
		chunk++;
	}
}

void	parted_a(t_stk **a, t_stk **str, t_stk **b)
{
	int		len;
	int		pivota;
	int		i;

	i = 0;
	pivota = findpivot(a, 0);
	len = ft_list_size(*a);
	if (len % 2 == 0 || len == 3 || len == 1)
		i = len / 2;
	else
		i = (len / 2) + 1;
	while (i != 0)
	{
		if ((*a)->num < pivota)
		{
			push_cmd(str, a, b, -4);
			i--;
		}
		else
			push_cmd(str, a, b, 3);
	}
}

void	parted_a_triple(t_stk **a, t_stk **str, t_stk **b)
{
	int		len;
	int		i;
	int		lower;
	int		upper;

	i = 0;
	lower = findpivot2(a, 1);
	upper = findpivot2(a, 0);
	len = ft_list_size(*a);
	i = len - (len / 3);
	while (i != 0)
	{
		if ((*a)->num < upper)
		{
			push_cmd(str, a, b, -4);
			if ((*b)->num < lower && ft_list_size(*b) > 1)
				push_cmd(str, a, b, -3);
			else
				(*b)->chunk = 1;
			i--;
		}
		else
			push_cmd(str, a, b, 3);
	}
}
