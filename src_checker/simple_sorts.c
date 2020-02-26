/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:00:38 by kysgramo          #+#    #+#             */
/*   Updated: 2020/01/29 22:00:42 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case3(t_stk **a, t_stk **str)
{
	long long	x;
	long long	y;
	long long	z;

	while (issorted(*a) != 1)
	{
		x = (*a)->num;
		y = (*a)->next->num;
		z = (*a)->next->next->num;
		if (x < y && y > z && x > z)
			push_cmd(str, a, NULL, 2);
		else if (x > y && y < z && x > z)
			push_cmd(str, a, NULL, 3);
		else
			push_cmd(str, a, NULL, 1);
	}
}

void	case4(t_stk **a, t_stk **str, t_stk **b)
{
	int		pivot;
	int		min;

	min = findmin(*a);
	pivot = findpivot(a, 0);
	while (ft_list_size(*a) != 3)
	{
		if ((*a)->num == min)
			push_cmd(str, a, b, -4);
		else
			push_cmd(str, a, b, 3);
	}
	case3(a, str);
	push_cmd(str, a, b, 4);
}

void	chunk0(t_stk **a)
{
	t_stk	*curr;

	curr = *a;
	while (curr->next != NULL)
	{
		curr = curr->next;
		curr->chunk = 0;
	}
}

void	case5(t_stk **a, t_stk **str, t_stk **b)
{
	int		pivot;

	chunk0(a);
	pivot = 3;
	pivot = findpivot(a, 0);
	while (ft_list_size(*a) != 3)
	{
		if ((*a)->num < pivot)
			push_cmd(str, a, b, -4);
		else
			push_cmd(str, a, b, 3);
	}
	case3(a, str);
	if ((*b)->num < (*b)->next->num)
		push_cmd(str, a, b, -1);
	push_cmd(str, a, b, 4);
	push_cmd(str, a, b, 4);
}
