/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:08:11 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 18:30:03 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_stk **a, int size)
{
	t_stk	*str;
	t_stk	*b;

	str = NULL;
	b = NULL;
	if (size == 2 && (*a)->num > (*a)->next->num)
		str = ft_create_elem(1);
	else if (size == 3)
		case3(a, &str);
	else if (size == 4)
		case4(a, &str, &b);
	else if (size == 5)
		case5(a, &str, &b);
	else if (size > 5 && size < 80)
		casesmall(a, &str, &b);
	else if (size >= 80 && size <= 500)
		case100(a, &str, &b);
	printlist_cmd(str);
	ft_list_clear(&str);
}

int		notnorm(t_stk **a)
{
	if (isanorm(*a) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (issorted(*a) == 1)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stk	*a;
	t_flg	*f;

	a = NULL;
	f = create_flg();
	if (argc > 1)
	{
		a = ft_push_params(argc, argv, f);
		if (notnorm(&a) == 1)
		{
			if (ft_list_size(a) == 1)
			{
				clean_flg(f);
				return (0);
			}
			sorter(&a, ft_list_size(a));
		}
	}
	ft_list_clear(&a);
	clean_flg(f);
	return (0);
}
