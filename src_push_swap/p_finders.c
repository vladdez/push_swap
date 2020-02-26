/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:57:35 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 15:16:45 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			findmin(t_stk *a)
{
	int		min;
	int		fullstep;
	int		minstep;
	t_stk	*curr;

	min = 2147483647;
	fullstep = 0;
	minstep = 0;
	curr = a;
	while (curr)
	{
		if (curr->num != 2147483647 && min > curr->num)
		{
			minstep = fullstep;
			min = curr->num;
		}
		curr = curr->next;
		fullstep++;
	}
	return (min);
}

int			findmin2(t_stk *a)
{
	int		min;
	int		fullstep;
	int		minstep;
	t_stk	*curr;

	min = 2147483647;
	fullstep = 0;
	minstep = 0;
	curr = a;
	while (curr)
	{
		fullstep++;
		if (curr->num != 2147483647 && min > curr->num)
		{
			minstep = fullstep;
			min = curr->num;
		}
		curr = curr->next;
	}
	return (minstep);
}

int			findmax2(t_stk *a)
{
	int		max;
	int		fullstep;
	int		maxstep;
	t_stk	*curr;

	max = -2147483648;
	fullstep = 0;
	maxstep = 0;
	curr = a;
	while (curr)
	{
		if (curr->num != -2147483648 && max < curr->num)
		{
			maxstep = fullstep;
			max = curr->num;
		}
		curr = curr->next;
		fullstep++;
	}
	return (maxstep);
}

int			findmax(t_stk *a)
{
	int		max;
	t_stk	*curr;

	max = -2147483648;
	curr = a;
	while (curr)
	{
		if (curr->num != -2147483648 && max < curr->num)
			max = curr->num;
		curr = curr->next;
	}
	return (max);
}
