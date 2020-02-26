/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_lock_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:03:53 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 17:03:56 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		comb_counter(t_stk **a, long long int numinb, t_cmd *cmds)
{
	long long	alowest;
	int			opnum;

	opnum = 0;
	alowest = findalowest(a);
	if (numinb > (*a)->num)
	{
		cmds->flag = 3;
		opnum = findforbhigher(a, numinb) + 1;
	}
	else if (numinb < (*a)->num && numinb < alowest)
	{
		cmds->flag = 2;
		opnum = findforblower(a, cmds->mostlowest, numinb);
	}
	else if (numinb < (*a)->num)
		opnum = 1;
	return (opnum);
}

void	opcounter_sub2(t_cmd *cmds, int cm, int unitnum, int currb)
{
	if (cm <= cmds->minnum)
	{
		if (cm < cmds->minnum || (cm == cmds->minnum && cmds->curr_b < currb))
		{
			cmds->minnum = cm;
			cmds->cmdinb = unitnum * cmds->flagb;
			cmds->curr_b = currb;
			if (cmds->flag == 3)
			{
				cmds->cmdina3 = cm - unitnum;
				cmds->cmdina2 = -1;
			}
			else if (cmds->flag == 2)
			{
				cmds->cmdina2 = cm - unitnum;
				cmds->cmdina3 = -1;
			}
		}
	}
}

int		opcounter_sub1(int stepinb, int len, t_cmd *cmds)
{
	int			unitnum;

	if (stepinb < (len / 2))
	{
		unitnum = stepinb;
		cmds->flagb = 1;
	}
	else
	{
		unitnum = len - stepinb;
		cmds->flagb = -1;
	}
	return (unitnum);
}

void	opcounter(t_stk **a, t_stk **b, t_cmd *cmds)
{
	int			len;
	int			unitnum;
	int			stepinb;
	int			cmdnum;
	long long	currbnum;

	cmds->minnum = 20000;
	cmds->cmdinb = 0;
	stepinb = 1;
	len = ft_list_size(*b);
	while (stepinb != len)
	{
		cmdnum = 0;
		unitnum = opcounter_sub1(stepinb, len, cmds);
		currbnum = take_num_in_b(b, stepinb);
		cmdnum = unitnum + comb_counter(a, currbnum, cmds);
		opcounter_sub2(cmds, cmdnum, unitnum, currbnum);
		stepinb++;
	}
}
