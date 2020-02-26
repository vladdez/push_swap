/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:47:37 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 18:37:23 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stk *a)
{
	long long	tmp;

	if (a != NULL)
	{
		if (a->next != NULL)
		{
			tmp = a->num;
			a->num = a->next->num;
			a->next->num = tmp;
		}
	}
}

void	ft_r(t_stk **a)
{
	t_stk		*del;
	t_stk		*curr;
	long long	tmp;

	curr = NULL;
	if (*a != NULL)
	{
		if ((*a)->next != NULL)
		{
			del = *a;
			tmp = del->num;
			*a = (*a)->next;
			free(del);
			curr = *a;
			while (curr->next)
				curr = curr->next;
			curr->next = ft_create_elem(tmp);
		}
	}
}

void	ft_rr(t_stk **a)
{
	t_stk		*del;
	t_stk		*curr;
	long long	tmp;

	curr = NULL;
	if (*a != NULL)
	{
		if ((*a)->next != NULL)
		{
			curr = *a;
			while (curr->next->next)
				curr = curr->next;
			del = curr->next;
			tmp = del->num;
			free(del);
			curr->next = NULL;
			ft_list_push_front(a, tmp);
		}
	}
}

void	ft_p(t_stk **from, t_stk **to, int sw)
{
	t_stk		*del;
	long long	tmp;

	if (*from != NULL)
	{
		if ((*from)->next == NULL && sw != 0)
			*from = NULL;
		else
		{
			del = *from;
			tmp = del->num;
			*from = (*from)->next;
			free(del);
			if (to == NULL)
				to = ft_create_elem(tmp);
			else
				ft_list_push_front(to, tmp);
		}
	}
}
