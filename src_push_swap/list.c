/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:47:46 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 16:14:03 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_create_elem(long long int x)
{
	t_stk	*a;

	if (!(a = (t_stk *)malloc(sizeof(t_stk))))
		return (NULL);
	a->num = x;
	a->chunk = 0;
	a->next = NULL;
	return (a);
}

void	ft_list_push_back(t_stk **begin_list, long long int x)
{
	t_stk	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(x);
	}
	else
		*begin_list = ft_create_elem(x);
}

void	ft_list_push_front(t_stk **begin_list, long long int x)
{
	t_stk	*list;

	list = ft_create_elem(x);
	list->next = *begin_list;
	*begin_list = list;
}

void	ft_list_clear(t_stk **a)
{
	t_stk *curra;
	t_stk *nexta;

	curra = *a;
	while (curra)
	{
		nexta = curra->next;
		free(curra);
		curra = nexta;
	}
	*a = NULL;
}

int		ft_list_size(t_stk *begin_list)
{
	int		i;
	t_stk	*curr;

	i = 0;
	curr = begin_list;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
