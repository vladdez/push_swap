/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:22:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/18 14:41:46 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ls_atoi(const char *str)
{
	unsigned long	res;
	int				minus;

	res = 0;
	minus = 1;
	if ((*str == '-' || *str == '+') && ft_strlen(str) == 1)
		return (MAXINT);
	if (*str == '-')
		minus = -1;
	if ((*str == '-' || *str == '+'))
		str++;
	while (*str != '\0')
	{
		if (!(*str <= '9' && *str >= '0'))
			return (MAXINT);
		res = (res * 10 + *str - 48);
		str++;
		if (minus == 1 && res >= 2147483648)
			return (MAXINT);
		if (minus == -1 && res > 2147483649)
			return (MAXINT);
	}
	return (res * minus);
}

int				isanorm(t_stk *a)
{
	t_stk	*curr;
	t_stk	*tmp;

	curr = a;
	while (curr->next)
	{
		if (!(curr->num < MAXINT && curr->num > -(MAXINT + 1L)))
			return (-1);
		tmp = curr;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (curr->num == tmp->num)
				return (-1);
		}
		curr = curr->next;
	}
	if (!(curr->num < MAXINT && curr->num > -(MAXINT + 1L)))
		return (-1);
	return (1);
}

int				iscmdnorm(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (0);
	else if (ft_strcmp(line, "sb") == 0)
		return (0);
	else if (ft_strcmp(line, "ss") == 0)
		return (0);
	else if (ft_strcmp(line, "pa") == 0)
		return (0);
	else if (ft_strcmp(line, "pb") == 0)
		return (0);
	else if (ft_strcmp(line, "ra") == 0)
		return (0);
	else if (ft_strcmp(line, "rb") == 0)
		return (0);
	else if (ft_strcmp(line, "rr") == 0)
		return (0);
	else if (ft_strcmp(line, "rra") == 0)
		return (0);
	else if (ft_strcmp(line, "rrb") == 0)
		return (0);
	else if (ft_strcmp(line, "rrr") == 0)
		return (0);
	else
		return (-1);
}

int				issorted(t_stk *a)
{
	t_stk *curr;

	curr = a;
	if (a->next == NULL)
		return (1);
	while (a->next != NULL)
	{
		if (a->num > a->next->num)
			return (-1);
		else
			a = a->next;
	}
	return (1);
}
