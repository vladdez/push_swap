/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:45:26 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 21:08:53 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_comb_lock_sub(t_stk **a, t_stk **str, t_stk **b, t_cmd *cmds)
{
	if (cmds->cmdina3 != -1 && cmds->cmdina2 == -1)
	{
		while (cmds->cmdinb != 0 && cmds->cmdina3 != 0)
		{
			push_cmd(str, a, b, 5);
			cmds->cmdinb--;
			cmds->cmdina3--;
		}
	}
	while (cmds->cmdinb != 0)
	{
		push_cmd(str, a, b, -3);
		cmds->cmdinb--;
	}
}

void	pre_comb_lock(t_stk **a, t_stk **str, t_stk **b, t_cmd *cmds)
{
	opcounter(a, b, cmds);
	if (cmds->cmdinb < 0)
	{
		if (cmds->cmdina2 != -1 && cmds->cmdina3 == -1)
		{
			while (cmds->cmdinb != 0 && cmds->cmdina2 != 0)
			{
				push_cmd(str, a, b, 6);
				cmds->cmdinb++;
				cmds->cmdina2--;
			}
		}
		while (cmds->cmdinb != 0)
		{
			push_cmd(str, a, b, -2);
			cmds->cmdinb++;
		}
	}
	else
		pre_comb_lock_sub(a, str, b, cmds);
}

void	comb_lock_sub(t_stk **a, t_stk **str, t_stk **b, t_cmd *cmds)
{
	long long	alowest;

	alowest = findalowest(a);
	if (cmds->curr_b > (*a)->num)
	{
		while (cmds->curr_b > (*a)->num)
		{
			push_cmd(str, a, b, 3);
		}
		push_cmd(str, a, b, 4);
	}
	else if (cmds->curr_b < (*a)->num && cmds->curr_b < alowest)
	{
		while (cmds->curr_b < alowest && alowest != cmds->mostlowest)
		{
			push_cmd(str, a, b, 2);
			alowest = findalowest(a);
		}
		push_cmd(str, a, b, 4);
	}
	else if (cmds->curr_b < (*a)->num)
		push_cmd(str, a, b, 4);
}

void	comb_lock(t_stk **a, t_stk **str, t_stk **b)
{
	t_cmd			*cmds;

	cmds = creatcmd();
	cmds->minb = findmin(*b);
	cmds->mostlowest = findalowest(a);
	while (ft_list_size(*b) != 0)
	{
		if (ft_list_size(*b) > 2)
			pre_comb_lock(a, str, b, cmds);
		if (ft_list_size(*b) == 2)
		{
			if ((*b)->num < (*b)->next->num)
				push_cmd(str, a, b, -1);
		}
		if (ft_list_size(*b) <= 2)
			cmds->curr_b = (*b)->num;
		comb_lock_sub(a, str, b, cmds);
	}
	clean_cmd(cmds);
}
