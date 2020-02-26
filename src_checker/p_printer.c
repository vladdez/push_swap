/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:43:39 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 15:43:42 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_cmd2(t_stk **a, t_stk **b, int i)
{
	if (i == 6)
	{
		ft_rr(a);
		ft_rr(b);
	}
	else if (i == 5)
	{
		ft_r(a);
		ft_r(b);
	}
}

void		push_cmd(t_stk **str, t_stk **a, t_stk **b, int cmd)
{
	long long i;

	i = (long long)cmd;
	if (i == 1)
		ft_s(*a);
	else if (i == -1)
		ft_s(*b);
	else if (i == 2)
		ft_rr(a);
	else if (i == 3)
		ft_r(a);
	else if (i == -2)
		ft_rr(b);
	else if (i == -3)
		ft_r(b);
	else if (i == 4)
		ft_p(b, a, 0);
	else if (i == -4)
		ft_p(a, b, 1);
	else if (i > 4)
		push_cmd2(a, b, i);
	ft_list_push_back(str, i);
}

void		printlist_cmd(t_stk *heada)
{
	t_stk *tempa;

	tempa = heada;
	if (heada != NULL)
	{
		while (tempa)
		{
			if (tempa->num == -1 || tempa->num == 1)
				write(1, "s", 1);
			else if (tempa->num == -2 || tempa->num == 2 || tempa->num == 6)
				write(1, "rr", 2);
			else if (tempa->num == -3 || tempa->num == 3 || tempa->num == 5)
				write(1, "r", 1);
			else if (tempa->num == -4 || tempa->num == 4)
				write(1, "p", 1);
			if (tempa->num == 5 || tempa->num == 6)
				write(1, "r\n", 2);
			else if (tempa->num > 0 && tempa->num < 5)
				write(1, "a\n", 2);
			else if (tempa->num < 0)
				write(1, "b\n", 2);
			tempa = tempa->next;
		}
	}
}

int			lenofchunk(t_stk **list, int chunk)
{
	int		len;
	t_stk	*tmp;

	tmp = *list;
	len = 0;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

void		printlist(t_stk *heada)
{
	t_stk *tempa;

	tempa = heada;
	if (heada != NULL)
	{
		if (tempa->next)
		{
			ft_printf(" {green} %lld {eoc}", tempa->num);
			while (tempa->next)
			{
				tempa = tempa->next;
				ft_printf("%lld ", tempa->num);
			}
		}
	}
	ft_printf("\n");
}
