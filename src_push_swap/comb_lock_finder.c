/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_lock_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:07:39 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 17:07:44 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	findalowest(t_stk **a)
{
	long long	alowest;
	t_stk		*tmpa;

	tmpa = *a;
	while (tmpa->next != NULL)
		tmpa = tmpa->next;
	alowest = tmpa->num;
	return (alowest);
}

int			findforbhigher(t_stk **a, long long int num)
{
	t_stk	*tmpa;
	int		step;

	tmpa = *a;
	step = 0;
	while (tmpa->num < num)
	{
		tmpa = tmpa->next;
		step++;
	}
	return (step);
}

int			findforblower(t_stk **a, long long lowest, long long num)
{
	t_stk		*tmpa;
	int			step;
	long long	alowest;

	alowest = findalowest(a);
	tmpa = *a;
	step = 0;
	if (alowest == lowest)
		return (0);
	if (alowest < num)
		return (0);
	while (tmpa->num != lowest)
		tmpa = tmpa->next;
	while (tmpa->next != NULL)
	{
		if (tmpa->num > num)
			step++;
		tmpa = tmpa->next;
	}
	return (step);
}

long long	take_num_in_b(t_stk **b, int unitnum)
{
	long long	num;
	t_stk		*tmpa;

	tmpa = *b;
	while (unitnum != 0)
	{
		tmpa = tmpa->next;
		unitnum--;
	}
	num = tmpa->num;
	return (num);
}
