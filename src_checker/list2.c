/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:25:52 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/12 16:59:04 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_params2(t_stk **heada, t_stk **curra, char **words)
{
	int i;

	i = 0;
	if (words != NULL)
	{
		while (words[i] != '\0')
			i++;
		if (i >= 1)
		{
			i--;
			while (i != -1)
			{
				*heada = ft_create_elem(ls_atoi(words[i]));
				(*heada)->next = *curra;
				*curra = *heada;
				free(words[i]);
				i--;
			}
		}
		free(words);
	}
}

t_stk	*ft_push_params(int ac, char **av, t_flg *f)
{
	t_stk	*heada;
	t_stk	*curra;
	int		i;
	char	**words;

	check_viz(ac, av, f);
	curra = NULL;
	i = -1;
	while (av[i + 1] != NULL)
		i++;
	heada = NULL;
	while (i > 0)
	{
		words = ft_strsplit(av[i], ' ');
		ft_push_params2(&heada, &curra, words);
		i--;
	}
	return (heada);
}
