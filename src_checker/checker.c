/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:08:01 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 14:55:35 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanshit(t_stk **a, t_stk **b, t_flg *f)
{
	if (b != NULL)
		ft_list_clear(b);
	if (b != NULL)
		ft_list_clear(a);
	clean_flg(f);
}

int		main_sub(t_stk **a, t_stk **b, char *line, t_flg *f)
{
	while (get_next_line(0, &line))
	{
		if (iscmdnorm(line) == -1)
		{
			write(2, "Error\n", 6);
			cleanshit(a, b, f);
			free(line);
			return (0);
		}
		usecmd(a, b, line);
		doviz(f, a, b, line);
		free(line);
	}
	if (*a == NULL)
		write(1, "\n", 1);
	else if (issorted(*a) == 1 && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	cleanshit(a, b, f);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;
	t_flg	*f;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		f = create_flg();
		a = ft_push_params(argc, argv, f);
		if (a != NULL)
		{
			if (isanorm(a) == -1)
			{
				write(2, "Error\n", 6);
				cleanshit(&a, &b, f);
				return (0);
			}
			if (main_sub(&a, &b, NULL, f) != 1)
				return (0);
		}
		else
			clean_flg(f);
	}
	return (0);
}
