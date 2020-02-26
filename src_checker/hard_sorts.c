/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:26:49 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 16:12:48 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pivchecker(t_stk **a, int pivot)
{
	t_stk	*tmpa;

	tmpa = *a;
	while (tmpa->next != NULL)
	{
		if (tmpa->num < pivot)
			return (-1);
		tmpa = tmpa->next;
	}
	return (1);
}

void	insertionsort_sub(t_stk **a, t_stk **str, t_stk **b, int len)
{
	int		maxstep;

	maxstep = findmax2(*b);
	if (maxstep == 1)
	{
		push_cmd(str, a, b, -1);
		maxstep--;
	}
	if (maxstep < (len / 2))
	{
		while (maxstep != 0)
		{
			push_cmd(str, a, b, -3);
			maxstep--;
		}
	}
	else if (maxstep > (len / 2))
	{
		while (maxstep != len)
		{
			push_cmd(str, a, b, -2);
			maxstep++;
		}
	}
}

void	insertionsort(t_stk **a, t_stk **str, t_stk **b)
{
	int		chunk;
	int		lench;
	int		len;

	chunk = (*b)->chunk;
	while (lenofchunk(b, chunk) < 26)
	{
		chunk = (*b)->chunk;
		lench = lenofchunk(b, chunk);
		while (lench != 0)
		{
			len = ft_list_size(*b);
			insertionsort_sub(a, str, b, len);
			push_cmd(str, a, b, 4);
			(*a)->chunk = -1;
			lench--;
			len--;
		}
		chunk = (*b)->chunk;
		lench = lenofchunk(b, chunk);
	}
}

void	algo(t_stk **a, t_stk **str, t_stk **b)
{
	int		i;

	partition_of_a(a, str, b);
	if (ft_list_size(*a) == 5)
		case5(a, str, b);
	else if (ft_list_size(*a) == 4)
		case4(a, str, b);
	else
		case3(a, str);
	(*a)->chunk = -1;
	if (ft_list_size(*b) > 50)
		insertionsort(a, str, b);
	comb_lock(a, str, b);
	i = findmin(*a);
	while ((*a)->num != i)
		push_cmd(str, a, b, 2);
}

void	case100(t_stk **a1, t_stk **str1, t_stk **b1)
{
	t_stk	*a2;
	t_stk	*str2;
	t_stk	*b2;

	a2 = NULL;
	str2 = NULL;
	b2 = NULL;
	ft_list_copy(a1, &a2, 0);
	parted_a_triple(&a2, &str2, &b2);
	parted_a(a1, str1, b1);
	algo(a1, str1, b1);
	algo(&a2, &str2, &b2);
	if (ft_list_size(*str1) > ft_list_size(str2))
	{
		ft_list_clear(str1);
		chunk0(&str2);
		ft_list_copy(&str2, str1, 0);
	}
	ft_list_clear(&str2);
	ft_list_clear(&a2);
}
