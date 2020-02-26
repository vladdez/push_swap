/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pivots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:42:47 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/17 14:12:31 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_list_copy(t_stk **a, t_stk **cpy, int chunk)
{
	t_stk	*tmpa;

	tmpa = *a;
	while (tmpa)
	{
		if (tmpa->chunk == chunk)
			ft_list_push_back(cpy, tmpa->num);
		tmpa = tmpa->next;
	}
}

void		ft_list_sort(t_stk *acpy)
{
	t_stk		*curr;
	long long	tmp;

	curr = NULL;
	if (ft_list_size(acpy) > 1)
	{
		curr = acpy;
		while (acpy->next != NULL)
		{
			if (acpy->num > acpy->next->num)
			{
				tmp = acpy->num;
				acpy->num = acpy->next->num;
				acpy->next->num = tmp;
				acpy = curr;
			}
			else
				acpy = acpy->next;
		}
	}
}

int			findpivot(t_stk **a, int chunk)
{
	int		len;
	t_stk	*acpy;
	t_stk	*curr;
	int		piv;

	acpy = NULL;
	curr = NULL;
	ft_list_copy(a, &acpy, chunk);
	len = ft_list_size(acpy);
	ft_list_sort(acpy);
	if (len % 2 == 0 || len == 3 || len == 1)
		len = len / 2;
	else if (len == 5)
		len = 2;
	else
		len = (len / 2) + 1;
	curr = acpy;
	while (len != 0)
	{
		len--;
		curr = curr->next;
	}
	piv = curr->num;
	ft_list_clear(&acpy);
	return (piv);
}

int			findpivot2(t_stk **a, int lower)
{
	int		len;
	t_stk	*acpy;
	t_stk	*curr;
	int		piv;

	piv = 0;
	acpy = NULL;
	curr = NULL;
	ft_list_copy(a, &acpy, 0);
	len = ft_list_size(acpy);
	ft_list_sort(acpy);
	if (lower == 1)
		len = len / 3;
	else
		len = len - (len / 3);
	curr = acpy;
	while (len != 0)
	{
		len--;
		curr = curr->next;
	}
	piv = curr->num;
	ft_list_clear(&acpy);
	return (piv);
}
